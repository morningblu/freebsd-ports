# New ports collection makefile for:   xpostit
# Date created:        6 May 1996
# Whom:                joerg
#
# $FreeBSD$
#

PORTNAME=	xpostit
PORTVERSION=	3.3.1
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	PostIt (R) messages onto your X11 screen

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
WRKSRC=		${WRKDIR}/xpostit
MAN1=		xpostit.1

.include <bsd.port.mk>
