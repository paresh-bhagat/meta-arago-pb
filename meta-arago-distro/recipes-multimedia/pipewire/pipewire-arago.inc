PR:append = ".arago1"

FILESEXTRAPATHS:prepend := "${THISDIR}/pipewire:"
SRC_URI:append = " file://pipewire.service"

# AM62D-specific config files
SRC_URI:append:am62dxx-evm = " \
    file://90-pipewire-sink.conf \
    file://91-pipewire-source.conf \
"

do_install:append() {
    if ${@bb.utils.contains('DISTRO_FEATURES', 'systemd', 'true', 'false', d)}; then
        install -d ${D}${systemd_system_unitdir}
        install -m 0644 ${UNPACKDIR}/pipewire.service ${D}${systemd_system_unitdir}/
    fi
}

do_install:append:am62dxx-evm() {
    install -d ${D}${sysconfdir}/pipewire/pipewire.conf.d
    install -m 0644 ${UNPACKDIR}/90-pipewire-sink.conf ${D}${sysconfdir}/pipewire/pipewire.conf.d/
    install -m 0644 ${UNPACKDIR}/91-pipewire-source.conf ${D}${sysconfdir}/pipewire/pipewire.conf.d/
}

FILES:${PN}:append:am62dxx-evm = " \
    ${sysconfdir}/pipewire/pipewire.conf.d/90-pipewire-sink.conf \
    ${sysconfdir}/pipewire/pipewire.conf.d/91-pipewire-source.conf \
"

PACKAGECONFIG:append = " pipewire-jack"
PACKAGECONFIG:remove = "jack"
