# New ports collection makefile for:	seabios-devel
# Date created:			Sat Sep 10 19:00:54 CEST 2011
# Whom:				Juergen Lock <nox@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	seabios-devel
PORTVERSION=	1.6.3.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.linuxtogo.org/~kevin/SeaBIOS/:release \
		LOCAL/nox/
DISTNAME=	${PORTNAME:S/-devel//}-${DISTVERSION:C/:(.)/\1/g}
DIST_SUBDIR=	qemu

MAINTAINER=	nox@FreeBSD.org
COMMENT=	SeaBIOS git snapshot (for emulators/qemu-devel)

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_PYTHON_BUILD=	yes
PATCH_STRIP=	-p1
ONLY_FOR_ARCHS=	amd64 i386
MAKE_JOBS_SAFE=	yes
# Doesn't run with qemu 0.11.1
CONFLICTS_INSTALL=	qemu-[0-9]*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900033
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin LD=${LOCALBASE}/bin/ld
.endif

PLIST_FILES=	share/qemu/bios.bin-${PORTVERSION}
PLIST_DIRSTRY=	share/qemu

post-patch:
	@${REINPLACE_CMD} s/elf32-i386/elf32-i386-freebsd/g \
		${WRKSRC}/tools/layoutrom.py \
		${WRKSRC}/vgasrc/vgalayout.lds.S
	@${REINPLACE_CMD} s/elf_i386/elf_i386_fbsd/g \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${PREFIX}/share/qemu
	@${INSTALL_DATA} ${WRKSRC}/out/bios.bin ${PREFIX}/${PLIST_FILES}

.include <bsd.port.post.mk>
