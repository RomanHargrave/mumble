TEMPLATE = subdirs
CONFIG += debug_and_release

SUBDIRS += speexbuild
SUBDIRS += src/mumble src/murmur

win32 {
  SUBDIRS += plugins
}
