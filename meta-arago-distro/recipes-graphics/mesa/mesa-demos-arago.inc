SECTION = ""

LIC_FILES_CHKSUM:remove = "file://src/xdemos/glxgears.c;beginline=1;endline=20;md5=914225785450eff644a86c871d3ae00e"

LIC_FILES_CHKSUM:append = " file://src/xdemos/glxgears.c;beginline=1;endline=20;md5=a481fbdb2ac800ecb12405c33bcfacae"

SRC_URI = "git://gitlab.freedesktop.org/mesa/demos.git;protocol=https;branch=main"
SRCREV = "02eae079cb0b8186064d5b194ca4cc2995f099ee"

PV = "9.0.0+git"

REQUIRED_DISTRO_FEATURES:remove = "x11"

PACKAGECONFIG += "${@bb.utils.filter('DISTRO_FEATURES', 'wayland', d)}"

PACKAGECONFIG[glut] = "-Dwith-glut=${STAGING_EXECPREFIXDIR},-Dglut=disabled,freeglut"
PACKAGECONFIG[osmesa] = "-Dosmesa=enabled,-Dosmesa=disabled,"
