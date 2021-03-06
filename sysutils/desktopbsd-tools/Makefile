# New ports collection Makefile for:	desktopbsd-tools
# Date created:				8 April 2006
# Whom:					Peter Hofer <ph@desktopbsd.net>
#
# $FreeBSD$

PORTNAME=	desktopbsd-tools
PORTVERSION=	1.6
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.desktopbsd.net/pub/DesktopBSD/Tools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DesktopBSD tools for easy system configuration

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		fastest_cvsup:${PORTSDIR}/sysutils/fastest_cvsup \
		portupgrade:${PORTSDIR}/ports-mgmt/portupgrade \
		portaudit:${PORTSDIR}/ports-mgmt/portaudit

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_KDEBASE_VER=3

QMAKE?=		qmake
QMAKESPEC?=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++
MAKE_ENV=	QTDIR="${QT_PREFIX}"

WRKSRC=		${WRKDIR}/${PORTNAME}
DATADIR=	${PREFIX}/share/desktopbsd

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		does not compile on 9.X
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		"/Installation/d; /Documentation/d; /InitialConf/d" \
		${WRKSRC}/desktopbsd.pro
	@${REINPLACE_CMD} -e "s|^PREFIX = .*|PREFIX = ${PREFIX}|g" ${WRKSRC}/desktopbsd.pro.inc

do-configure:
	@cd ${WRKSRC} \
	&& ${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${QMAKESPEC} desktopbsd.pro \
	&& ${SETENV} ${MAKE_ENV} ./prepare_build.sh

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
