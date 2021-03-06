# New ports collection makefile for:	odamex
# Date created:				2007-12-06
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	odamex
PORTVERSION=	0.5.6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Odamex/${PORTVERSION}
DISTNAME=	odamex-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Standard in Online Multiplayer Doom

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer

OPTIONS_DEFINE= LAUNCHER MIDI

LAUNCHER_DESC=	Enable GUI launcher program
MIDI_DESC=	Enable MIDI support (timidity)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLAUNCHER}
USE_WX=		2.6+
MAKE_ENV+=	WXRC_CMD="${WXRC_CMD}" WITH_LAUNCHER=yes
PLIST_SUB+=	LAUNCHER=""
.else
PLIST_SUB+=	LAUNCHER="@comment "
.endif

.if ${PORT_OPTIONS:MMIDI}
RUN_DEPENDS+=	timidity:${PORTSDIR}/audio/timidity
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DMDIR%%|${DMDIR}|; \
		s|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/client/src/d_main.cpp \
		${WRKSRC}/server/src/d_main.cpp

.if ${PORT_OPTIONS:MLAUNCHER}
	@${REINPLACE_CMD} -e 's|\./odamex|odamex|' \
		${WRKSRC}/odalaunch/src/misc.cpp
.endif

do-install:
.for f in odamex odasrv
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MLAUNCHER}
	${INSTALL_PROGRAM} ${WRKSRC}/odalaunch/odalaunch ${PREFIX}/bin
.endif
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/odamex.wad ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.mk>
