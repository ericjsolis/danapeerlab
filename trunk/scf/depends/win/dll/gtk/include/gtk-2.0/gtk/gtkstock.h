/* GTK - The GIMP Toolkit
 * Copyright (C) 2000 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/*
 * Modified by the GTK+ Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/gtk/.
 */

#if defined(GTK_DISABLE_SINGLE_INCLUDES) && !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#ifndef __GTK_STOCK_H__
#define __GTK_STOCK_H__


#include <gdk/gdk.h>
#include <gtk/gtktypeutils.h> /* for GtkTranslateFunc */

G_BEGIN_DECLS

typedef struct _GtkStockItem GtkStockItem;

struct _GtkStockItem
{
  gchar *stock_id;
  gchar *label;
  GdkModifierType modifier;
  guint keyval;
  gchar *translation_domain;
};

void     gtk_stock_add        (const GtkStockItem  *items,
                               guint                n_items);
void     gtk_stock_add_static (const GtkStockItem  *items,
                               guint                n_items);
gboolean gtk_stock_lookup     (const gchar         *stock_id,
                               GtkStockItem        *item);

/* Should free the list (and free each string in it also).
 * This function is only useful for GUI builders and such.
 */
GSList*  gtk_stock_list_ids  (void);

GtkStockItem *gtk_stock_item_copy (const GtkStockItem *item);
void          gtk_stock_item_free (GtkStockItem       *item);

void          gtk_stock_set_translate_func (const gchar      *domain,
					    GtkTranslateFunc  func,
					    gpointer          data,
					    GDestroyNotify    notify);

/* Stock IDs (not all are stock items; some are images only) */
/**
 * GTK_STOCK_ABOUT:
 *
 * The "About" item.
 * <inlinegraphic fileref="gtk-about.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 */
#define GTK_STOCK_ABOUT            "gtk-about"

/**
 * GTK_STOCK_ADD:
 *
 * The "Add" item.
 * <inlinegraphic fileref="gtk-add.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_ADD              "gtk-add"

/**
 * GTK_STOCK_APPLY:
 *
 * The "Apply" item.
 * <inlinegraphic fileref="gtk-apply.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_APPLY            "gtk-apply"

/**
 * GTK_STOCK_BOLD:
 *
 * The "Bold" item.
 * <inlinegraphic fileref="gtk-bold.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_BOLD             "gtk-bold"

/**
 * GTK_STOCK_CANCEL:
 *
 * The "Cancel" item.
 * <inlinegraphic fileref="gtk-cancel.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_CANCEL           "gtk-cancel"

/**
 * GTK_STOCK_CAPS_LOCK_WARNING:
 *
 * The "Caps Lock Warning" icon.
 * <inlinegraphic fileref="gtk-caps-lock-warning.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.16
 */
#define GTK_STOCK_CAPS_LOCK_WARNING "gtk-caps-lock-warning"

/**
 * GTK_STOCK_CDROM:
 *
 * The "CD-Rom" item.
 * <inlinegraphic fileref="gtk-cdrom.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_CDROM            "gtk-cdrom"

/**
 * GTK_STOCK_CLEAR:
 *
 * The "Clear" item.
 * <inlinegraphic fileref="gtk-clear.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_CLEAR            "gtk-clear"

/**
 * GTK_STOCK_CLOSE:
 *
 * The "Close" item.
 * <inlinegraphic fileref="gtk-close.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_CLOSE            "gtk-close"

/**
 * GTK_STOCK_COLOR_PICKER:
 *
 * The "Color Picker" item.
 * <inlinegraphic fileref="gtk-color-picker.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.2
 */
#define GTK_STOCK_COLOR_PICKER     "gtk-color-picker"

/**
 * GTK_STOCK_CONNECT:
 *
 * The "Connect" icon.
 * <inlinegraphic fileref="gtk-connect.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 */
#define GTK_STOCK_CONNECT          "gtk-connect"

/**
 * GTK_STOCK_CONVERT:
 *
 * The "Convert" item.
 * <inlinegraphic fileref="gtk-convert.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_CONVERT          "gtk-convert"

/**
 * GTK_STOCK_COPY:
 *
 * The "Copy" item.
 * <inlinegraphic fileref="gtk-copy.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_COPY             "gtk-copy"

/**
 * GTK_STOCK_CUT:
 *
 * The "Cut" item.
 * <inlinegraphic fileref="gtk-cut.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_CUT              "gtk-cut"

/**
 * GTK_STOCK_DELETE:
 *
 * The "Delete" item.
 * <inlinegraphic fileref="gtk-delete.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_DELETE           "gtk-delete"

/**
 * GTK_STOCK_DIALOG_AUTHENTICATION:
 *
 * The "Authentication" item.
 * <inlinegraphic fileref="gtk-dialog-authentication.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.4
 */
#define GTK_STOCK_DIALOG_AUTHENTICATION "gtk-dialog-authentication"

/**
 * GTK_STOCK_DIALOG_INFO:
 *
 * The "Information" item.
 * <inlinegraphic fileref="gtk-dialog-info.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_DIALOG_INFO      "gtk-dialog-info"

/**
 * GTK_STOCK_DIALOG_WARNING:
 *
 * The "Warning" item.
 * <inlinegraphic fileref="gtk-dialog-warning.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_DIALOG_WARNING   "gtk-dialog-warning"

/**
 * GTK_STOCK_DIALOG_ERROR:
 *
 * The "Error" item.
 * <inlinegraphic fileref="gtk-dialog-error.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_DIALOG_ERROR     "gtk-dialog-error"

/**
 * GTK_STOCK_DIALOG_QUESTION:
 *
 * The "Question" item.
 * <inlinegraphic fileref="gtk-dialog-question.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_DIALOG_QUESTION  "gtk-dialog-question"

/**
 * GTK_STOCK_DIRECTORY:
 *
 * The "Directory" icon.
 * <inlinegraphic fileref="gtk-directory.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 */
#define GTK_STOCK_DIRECTORY        "gtk-directory"

/**
 * GTK_STOCK_DISCARD:
 *
 * The "Discard" item.
 *
 * Since: 2.12
 */
#define GTK_STOCK_DISCARD          "gtk-discard"

/**
 * GTK_STOCK_DISCONNECT:
 *
 * The "Disconnect" icon.
 * <inlinegraphic fileref="gtk-disconnect.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 */
#define GTK_STOCK_DISCONNECT       "gtk-disconnect"

/**
 * GTK_STOCK_DND:
 *
 * The "Drag-And-Drop" icon.
 * <inlinegraphic fileref="gtk-dnd.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_DND              "gtk-dnd"

/**
 * GTK_STOCK_DND_MULTIPLE:
 *
 * The "Drag-And-Drop multiple" icon.
 * <inlinegraphic fileref="gtk-dnd-multiple.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_DND_MULTIPLE     "gtk-dnd-multiple"

/**
 * GTK_STOCK_EDIT:
 *
 * The "Edit" item.
 * <inlinegraphic fileref="gtk-edit.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 */
#define GTK_STOCK_EDIT             "gtk-edit"

/**
 * GTK_STOCK_EXECUTE:
 *
 * The "Execute" item.
 * <inlinegraphic fileref="gtk-execute.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_EXECUTE          "gtk-execute"

/**
 * GTK_STOCK_FILE:
 *
 * The "File" icon.
 * <inlinegraphic fileref="gtk-file.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 */
#define GTK_STOCK_FILE             "gtk-file"

/**
 * GTK_STOCK_FIND:
 *
 * The "Find" item.
 * <inlinegraphic fileref="gtk-find.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_FIND             "gtk-find"

/**
 * GTK_STOCK_FIND_AND_REPLACE:
 *
 * The "Find and Replace" item.
 * <inlinegraphic fileref="gtk-find-and-replace.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_FIND_AND_REPLACE "gtk-find-and-replace"

/**
 * GTK_STOCK_FLOPPY:
 *
 * The "Floppy" item.
 * <inlinegraphic fileref="gtk-floppy.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_FLOPPY           "gtk-floppy"

/**
 * GTK_STOCK_FULLSCREEN:
 *
 * The "Fullscreen" item.
 * <inlinegraphic fileref="gtk-fullscreen.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.8
 */
#define GTK_STOCK_FULLSCREEN       "gtk-fullscreen"

/**
 * GTK_STOCK_GOTO_BOTTOM:
 *
 * The "Bottom" item.
 * <inlinegraphic fileref="gtk-goto-bottom.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_GOTO_BOTTOM      "gtk-goto-bottom"

/**
 * GTK_STOCK_GOTO_FIRST:
 *
 * The "First" item.
 * <inlinegraphic fileref="gtk-goto-first-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-goto-first-rtl.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_GOTO_FIRST       "gtk-goto-first"

/**
 * GTK_STOCK_GOTO_LAST:
 *
 * The "Last" item.
 * <inlinegraphic fileref="gtk-goto-last-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-goto-last-rtl.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_GOTO_LAST        "gtk-goto-last"

/**
 * GTK_STOCK_GOTO_TOP:
 *
 * The "Top" item.
 * <inlinegraphic fileref="gtk-goto-top.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_GOTO_TOP         "gtk-goto-top"

/**
 * GTK_STOCK_GO_BACK:
 *
 * The "Back" item.
 * <inlinegraphic fileref="gtk-go-back-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-go-back-rtl.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_GO_BACK          "gtk-go-back"

/**
 * GTK_STOCK_GO_DOWN:
 *
 * The "Down" item.
 * <inlinegraphic fileref="gtk-go-down.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_GO_DOWN          "gtk-go-down"

/**
 * GTK_STOCK_GO_FORWARD:
 *
 * The "Forward" item.
 * <inlinegraphic fileref="gtk-go-forward-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-go-forward-rtl.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_GO_FORWARD       "gtk-go-forward"

/**
 * GTK_STOCK_GO_UP:
 *
 * The "Up" item.
 * <inlinegraphic fileref="gtk-go-up.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_GO_UP            "gtk-go-up"

/**
 * GTK_STOCK_HARDDISK:
 *
 * The "Harddisk" item.
 * <inlinegraphic fileref="gtk-harddisk.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.4
 */
#define GTK_STOCK_HARDDISK         "gtk-harddisk"

/**
 * GTK_STOCK_HELP:
 *
 * The "Help" item.
 * <inlinegraphic fileref="gtk-help.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_HELP             "gtk-help"

/**
 * GTK_STOCK_HOME:
 *
 * The "Home" item.
 * <inlinegraphic fileref="gtk-home.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_HOME             "gtk-home"

/**
 * GTK_STOCK_INDEX:
 *
 * The "Index" item.
 * <inlinegraphic fileref="gtk-index.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_INDEX            "gtk-index"

/**
 * GTK_STOCK_INDENT:
 *
 * The "Indent" item.
 * <inlinegraphic fileref="gtk-indent-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-indent-rtl.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.4
 */
#define GTK_STOCK_INDENT           "gtk-indent"

/**
 * GTK_STOCK_INFO:
 *
 * The "Info" item.
 * <inlinegraphic fileref="gtk-info.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.8
 */
#define GTK_STOCK_INFO             "gtk-info"

/**
 * GTK_STOCK_ITALIC:
 *
 * The "Italic" item.
 * <inlinegraphic fileref="gtk-italic.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_ITALIC           "gtk-italic"

/**
 * GTK_STOCK_JUMP_TO:
 *
 * The "Jump to" item.
 * <inlinegraphic fileref="gtk-jump-to-ltr.png" format="PNG"></inlinegraphic>
 * RTL-variant
 * <inlinegraphic fileref="gtk-jump-to-rtl.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_JUMP_TO          "gtk-jump-to"

/**
 * GTK_STOCK_JUSTIFY_CENTER:
 *
 * The "Center" item.
 * <inlinegraphic fileref="gtk-justify-center.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_JUSTIFY_CENTER   "gtk-justify-center"

/**
 * GTK_STOCK_JUSTIFY_FILL:
 *
 * The "Fill" item.
 * <inlinegraphic fileref="gtk-justify-fill.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_JUSTIFY_FILL     "gtk-justify-fill"

/**
 * GTK_STOCK_JUSTIFY_LEFT:
 *
 * The "Left" item.
 * <inlinegraphic fileref="gtk-justify-left.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_JUSTIFY_LEFT     "gtk-justify-left"

/**
 * GTK_STOCK_JUSTIFY_RIGHT:
 *
 * The "Right" item.
 * <inlinegraphic fileref="gtk-justify-right.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_JUSTIFY_RIGHT    "gtk-justify-right"

/**
 * GTK_STOCK_LEAVE_FULLSCREEN:
 *
 * The "Leave Fullscreen" item.
 * <inlinegraphic fileref="gtk-leave-fullscreen.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.8
 */
#define GTK_STOCK_LEAVE_FULLSCREEN "gtk-leave-fullscreen"

/**
 * GTK_STOCK_MISSING_IMAGE:
 *
 * The "Missing image" icon.
 * <inlinegraphic fileref="gtk-missing-image.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_MISSING_IMAGE    "gtk-missing-image"

/**
 * GTK_STOCK_MEDIA_FORWARD:
 *
 * The "Media Forward" item.
 * <inlinegraphic fileref="gtk-media-forward-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-media-forward-rtl.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 */
#define GTK_STOCK_MEDIA_FORWARD    "gtk-media-forward"

/**
 * GTK_STOCK_MEDIA_NEXT:
 *
 * The "Media Next" item.
 * <inlinegraphic fileref="gtk-media-next-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-media-next-rtl.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 */
#define GTK_STOCK_MEDIA_NEXT       "gtk-media-next"

/**
 * GTK_STOCK_MEDIA_PAUSE:
 *
 * The "Media Pause" item.
 * <inlinegraphic fileref="gtk-media-pause.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 */
#define GTK_STOCK_MEDIA_PAUSE      "gtk-media-pause"

/**
 * GTK_STOCK_MEDIA_PLAY:
 *
 * The "Media Play" item.
 * <inlinegraphic fileref="gtk-media-play-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-media-play-rtl.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 */
#define GTK_STOCK_MEDIA_PLAY       "gtk-media-play"

/**
 * GTK_STOCK_MEDIA_PREVIOUS:
 *
 * The "Media Previous" item.
 * <inlinegraphic fileref="gtk-media-previous-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-media-previous-rtl.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 */
#define GTK_STOCK_MEDIA_PREVIOUS   "gtk-media-previous"

/**
 * GTK_STOCK_MEDIA_RECORD:
 *
 * The "Media Record" item.
 * <inlinegraphic fileref="gtk-media-record.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 */
#define GTK_STOCK_MEDIA_RECORD     "gtk-media-record"

/**
 * GTK_STOCK_MEDIA_REWIND:
 *
 * The "Media Rewind" item.
 * <inlinegraphic fileref="gtk-media-rewind-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-media-rewind-rtl.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 */
#define GTK_STOCK_MEDIA_REWIND     "gtk-media-rewind"

/**
 * GTK_STOCK_MEDIA_STOP:
 *
 * The "Media Stop" item.
 * <inlinegraphic fileref="gtk-media-stop.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 */
#define GTK_STOCK_MEDIA_STOP       "gtk-media-stop"

/**
 * GTK_STOCK_NETWORK:
 *
 * The "Network" item.
 * <inlinegraphic fileref="gtk-network.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.4
 */
#define GTK_STOCK_NETWORK          "gtk-network"

/**
 * GTK_STOCK_NEW:
 *
 * The "New" item.
 * <inlinegraphic fileref="gtk-new.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_NEW              "gtk-new"

/**
 * GTK_STOCK_NO:
 *
 * The "No" item.
 * <inlinegraphic fileref="gtk-no.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_NO               "gtk-no"

/**
 * GTK_STOCK_OK:
 *
 * The "OK" item.
 * <inlinegraphic fileref="gtk-ok.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_OK               "gtk-ok"

/**
 * GTK_STOCK_OPEN:
 *
 * The "Open" item.
 * <inlinegraphic fileref="gtk-open.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_OPEN             "gtk-open"

/**
 * GTK_STOCK_ORIENTATION_PORTRAIT:
 *
 * The "Portrait Orientation" item.
 * <inlinegraphic fileref="gtk-orientation-portrait.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.10
 */
#define GTK_STOCK_ORIENTATION_PORTRAIT "gtk-orientation-portrait"

/**
 * GTK_STOCK_ORIENTATION_LANDSCAPE:
 *
 * The "Landscape Orientation" item.
 * <inlinegraphic fileref="gtk-orientation-landscape.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.10
 */
#define GTK_STOCK_ORIENTATION_LANDSCAPE "gtk-orientation-landscape"

/**
 * GTK_STOCK_ORIENTATION_REVERSE_LANDSCAPE:
 *
 * The "Reverse Landscape Orientation" item.
 * <inlinegraphic fileref="gtk-orientation-reverse-landscape.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.10
 */
#define GTK_STOCK_ORIENTATION_REVERSE_LANDSCAPE "gtk-orientation-reverse-landscape"

/**
 * GTK_STOCK_ORIENTATION_REVERSE_PORTRAIT:
 *
 * The "Reverse Portrait Orientation" item.
 * <inlinegraphic fileref="gtk-orientation-reverse-portrait.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.10
 */
#define GTK_STOCK_ORIENTATION_REVERSE_PORTRAIT "gtk-orientation-reverse-portrait"

/**
 * GTK_STOCK_PAGE_SETUP:
 *
 * The "Page Setup" item.
 * <inlinegraphic fileref="gtk-page-setup.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.14
 */
#define GTK_STOCK_PAGE_SETUP       "gtk-page-setup"

/**
 * GTK_STOCK_PASTE:
 *
 * The "Paste" item.
 * <inlinegraphic fileref="gtk-paste.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_PASTE            "gtk-paste"

/**
 * GTK_STOCK_PREFERENCES:
 *
 * The "Preferences" item.
 * <inlinegraphic fileref="gtk-preferences.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_PREFERENCES      "gtk-preferences"

/**
 * GTK_STOCK_PRINT:
 *
 * The "Print" item.
 * <inlinegraphic fileref="gtk-print.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_PRINT            "gtk-print"

/**
 * GTK_STOCK_PRINT_ERROR:
 *
 * The "Print Error" icon.
 * <inlinegraphic fileref="gtk-print-error.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.14
 */
#define GTK_STOCK_PRINT_ERROR      "gtk-print-error"

/**
 * GTK_STOCK_PRINT_PAUSED:
 *
 * The "Print Paused" icon.
 * <inlinegraphic fileref="gtk-print-paused.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.14
 */
#define GTK_STOCK_PRINT_PAUSED     "gtk-print-paused"

/**
 * GTK_STOCK_PRINT_PREVIEW:
 *
 * The "Print Preview" item.
 * <inlinegraphic fileref="gtk-print-preview.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_PRINT_PREVIEW    "gtk-print-preview"

/**
 * GTK_STOCK_PRINT_REPORT:
 *
 * The "Print Report" icon.
 * <inlinegraphic fileref="gtk-print-report.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.14
 */
#define GTK_STOCK_PRINT_REPORT     "gtk-print-report"


/**
 * GTK_STOCK_PRINT_WARNING:
 *
 * The "Print Warning" icon.
 * <inlinegraphic fileref="gtk-print-warning.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.14
 */
#define GTK_STOCK_PRINT_WARNING    "gtk-print-warning"

/**
 * GTK_STOCK_PROPERTIES:
 *
 * The "Properties" item.
 * <inlinegraphic fileref="gtk-properties.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_PROPERTIES       "gtk-properties"

/**
 * GTK_STOCK_QUIT:
 *
 * The "Quit" item.
 * <inlinegraphic fileref="gtk-quit.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_QUIT             "gtk-quit"

/**
 * GTK_STOCK_REDO:
 *
 * The "Redo" item.
 * <inlinegraphic fileref="gtk-redo-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-redo-rtl.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_REDO             "gtk-redo"

/**
 * GTK_STOCK_REFRESH:
 *
 * The "Refresh" item.
 * <inlinegraphic fileref="gtk-refresh.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_REFRESH          "gtk-refresh"

/**
 * GTK_STOCK_REMOVE:
 *
 * The "Remove" item.
 * <inlinegraphic fileref="gtk-remove.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_REMOVE           "gtk-remove"

/**
 * GTK_STOCK_REVERT_TO_SAVED:
 *
 * The "Revert" item.
 * <inlinegraphic fileref="gtk-revert-to-saved-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-revert-to-saved-rtl.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_REVERT_TO_SAVED  "gtk-revert-to-saved"

/**
 * GTK_STOCK_SAVE:
 *
 * The "Save" item.
 * <inlinegraphic fileref="gtk-save.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_SAVE             "gtk-save"

/**
 * GTK_STOCK_SAVE_AS:
 *
 * The "Save As" item.
 * <inlinegraphic fileref="gtk-save-as.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_SAVE_AS          "gtk-save-as"

/**
 * GTK_STOCK_SELECT_ALL:
 *
 * The "Select All" item.
 * <inlinegraphic fileref="gtk-select-all.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.10
 */
#define GTK_STOCK_SELECT_ALL       "gtk-select-all"

/**
 * GTK_STOCK_SELECT_COLOR:
 *
 * The "Color" item.
 * <inlinegraphic fileref="gtk-select-color.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_SELECT_COLOR     "gtk-select-color"

/**
 * GTK_STOCK_SELECT_FONT:
 *
 * The "Font" item.
 * <inlinegraphic fileref="gtk-font.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_SELECT_FONT      "gtk-select-font"

/**
 * GTK_STOCK_SORT_ASCENDING:
 *
 * The "Ascending" item.
 * <inlinegraphic fileref="gtk-sort-ascending.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_SORT_ASCENDING   "gtk-sort-ascending"

/**
 * GTK_STOCK_SORT_DESCENDING:
 *
 * The "Descending" item.
 * <inlinegraphic fileref="gtk-sort-descending.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_SORT_DESCENDING  "gtk-sort-descending"

/**
 * GTK_STOCK_SPELL_CHECK:
 *
 * The "Spell Check" item.
 * <inlinegraphic fileref="gtk-spell-check.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_SPELL_CHECK      "gtk-spell-check"

/**
 * GTK_STOCK_STOP:
 *
 * The "Stop" item.
 * <inlinegraphic fileref="gtk-stop.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_STOP             "gtk-stop"

/**
 * GTK_STOCK_STRIKETHROUGH:
 *
 * The "Strikethrough" item.
 * <inlinegraphic fileref="gtk-strikethrough.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_STRIKETHROUGH    "gtk-strikethrough"

/**
 * GTK_STOCK_UNDELETE:
 *
 * The "Undelete" item.
 * <inlinegraphic fileref="gtk-undelete-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-undelete-rtl.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_UNDELETE         "gtk-undelete"

/**
 * GTK_STOCK_UNDERLINE:
 *
 * The "Underline" item.
 * <inlinegraphic fileref="gtk-underline.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_UNDERLINE        "gtk-underline"

/**
 * GTK_STOCK_UNDO:
 *
 * The "Undo" item.
 * <inlinegraphic fileref="gtk-undo-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-undo-rtl.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_UNDO             "gtk-undo"

/**
 * GTK_STOCK_UNINDENT:
 *
 * The "Unindent" item.
 * <inlinegraphic fileref="gtk-unindent-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-unindent-rtl.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.4
 */
#define GTK_STOCK_UNINDENT         "gtk-unindent"

/**
 * GTK_STOCK_YES:
 *
 * The "Yes" item.
 * <inlinegraphic fileref="gtk-yes.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_YES              "gtk-yes"

/**
 * GTK_STOCK_ZOOM_100:
 *
 * The "Zoom 100%" item.
 * <inlinegraphic fileref="gtk-zoom-100.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_ZOOM_100         "gtk-zoom-100"

/**
 * GTK_STOCK_ZOOM_FIT:
 *
 * The "Zoom to Fit" item.
 * <inlinegraphic fileref="gtk-zoom-fit.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_ZOOM_FIT         "gtk-zoom-fit"

/**
 * GTK_STOCK_ZOOM_IN:
 *
 * The "Zoom In" item.
 * <inlinegraphic fileref="gtk-zoom-in.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_ZOOM_IN          "gtk-zoom-in"

/**
 * GTK_STOCK_ZOOM_OUT:
 *
 * The "Zoom Out" item.
 * <inlinegraphic fileref="gtk-zoom-out.png" format="PNG"></inlinegraphic>
 */
#define GTK_STOCK_ZOOM_OUT         "gtk-zoom-out"

G_END_DECLS

#endif /* __GTK_STOCK_H__ */
