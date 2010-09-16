import os
import imp
import sys
from compat import B

def imp_find_module(name, path=None):
    """
    same as imp.find_module, but handles dotted names
    """
    names = name.split('.')
    if path is not None:
        path = [os.path.realpath(path)]
    for name in names:
        result = imp.find_module(name, path)
        path = [result[1]]
    return result

def _check_importer_for_path(name, path_item):
    try:
        importer = sys.path_importer_cache[path_item]
    except KeyError:
        for path_hook in sys.path_hooks:
            try:
                importer = path_hook(path_item)
                break
            except ImportError:
                pass
        else:
            importer = None
        sys.path_importer_cache.setdefault(path_item, importer)


    if importer is None:
        try:
            return imp.find_module(name, [path_item])
        except ImportError, e:
            return None
    return importer.find_module(name)

def imp_walk(name):
    """
    yields namepart, tuple_or_importer for each path item

    raise ImportError if a name can not be found.
    """
    if name in sys.builtin_module_names:
        yield name, (None, None, ("", "", imp.C_BUILTIN))
        return
    paths = sys.path
    res = None
    for namepart in name.split('.'):
        for path_item in paths:
            res = _check_importer_for_path(namepart, path_item)
            if hasattr(res, 'find_module'):
                break
        else:
            break

        yield namepart, res
        paths = [os.path.join(path_item, namepart)]
    else:
        return

    raise ImportError('No module named %s' % (name,))


if sys.version_info[0] != 2:
    import re
    cookie_re = re.compile(B("coding[:=]\s*([-\w.]+)"))

    def guess_encoding(fp):

        for i in range(2):
            ln = fp.readline()

            m = cookie_re.search(ln)
            if m is not None:
                return m.group(1).decode('ascii')

        return 'utf-8'