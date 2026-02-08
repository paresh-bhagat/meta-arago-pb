PR:append = ".arago1"

FILESEXTRAPATHS:prepend:am62dxx-evm := "${THISDIR}/wireplumber:"

SRC_URI:append:am62dxx-evm = " \
    file://set-audio-defaults.sh \
    file://set-audio-defaults.service \
"

do_install:append:am62dxx-evm() {
    install -d ${D}${bindir}
    install -m 0755 ${UNPACKDIR}/set-audio-defaults.sh ${D}${bindir}/

    if ${@bb.utils.contains('DISTRO_FEATURES', 'systemd', 'true', 'false', d)}; then
        install -d ${D}${systemd_system_unitdir}
        install -m 0644 ${UNPACKDIR}/set-audio-defaults.service ${D}${systemd_system_unitdir}/
    fi
}

SYSTEMD_SERVICE:${PN}:append = " wireplumber.service"
SYSTEMD_SERVICE:${PN}:append:am62dxx-evm = " set-audio-defaults.service"

FILES:${PN}:append:am62dxx-evm = " ${bindir}/set-audio-defaults.sh"
