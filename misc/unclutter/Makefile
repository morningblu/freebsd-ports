# New ports collection makefile for:	unclutter
# Date created:		03 Aug 1996
# Whom:			shanee@augusta.de
#
# $FreeBSD$
#

PORTNAME=	unclutter
PORTVERSION=	8
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	simon@olofsson.de
COMMENT=	Remove idle cursor image from screen

WRKSRC=		${WRKDIR}/unclutter
USE_IMAKE=	yes
USE_XORG=	x11 xext
MAN1=		unclutter.1
PLIST_FILES=	bin/unclutter

.include <bsd.port.mk>
