# New ports collection makefile for:	ruby-gio2
# Date created:		2011-08-17
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gio2
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
CATEGORIES=	devel gnome ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	${RUBY_GNOME_DIST_SUBDIR}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding of GIO

BUILD_DEPENDS+=	${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/glib2.so:${PORTSDIR}/devel/ruby-glib2
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_GNOME=	glib20

CONFIGURE_ARGS=	--with-pkg-config-dir=${LOCALBASE}/libdata/pkgconfig

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

WRKSRC=	${RUBY_GNOME_WRKSRC}/${PORTNAME}
INSTALL_TARGET=	site-install install

PORTDOCS=	README
DOCSDIR=	${RUBY_MODDOCDIR}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
