# New ports collection makefile for:	glife
# Date created:				18th May 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glife
PORTVERSION=	0.2.1
PORTREVISION=	11
CATEGORIES=	games gnome
MASTER_SITES=	SF
DISTNAME=	gLife-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Conway's Game of Life for GNOME

GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack libglade
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		s|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
