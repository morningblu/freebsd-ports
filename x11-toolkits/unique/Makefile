# New ports collection makefile for:   libunique
# Date created:			22 Feb 2009
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/unique/Makefile,v 1.9 2010/06/29 21:14:06 kwm Exp $
#

PORTNAME=	unique
PORTVERSION=	1.1.6
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME/sources/lib${PORTNAME}/${PORTVERSION:R}/
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library for single instance applications

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus

USE_XORG=	ice
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gtk20 gnomeprefix ltverhack:2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-maintainer-flags
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/configure ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
