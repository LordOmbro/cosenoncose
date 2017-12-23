#!/usr/bin/python3
import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk


class Handler:
    def onDeleteWindow(self, *args):
        Gtk.main_quit(*args)

    def _clicked(self, button):
        print("Hello World!")


builder = Gtk.Builder()
builder.add_from_file("gtk.xml")
builder.connect_signals(Handler())

window = builder.get_object("window0")
window.connect("delete-event", Gtk.main_quit)
window.show_all()

Gtk.main()
