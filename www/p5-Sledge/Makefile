# New ports collection makefile for:	p5-Sledge
# Date created:		26 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Sledge
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	sledge/8401
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A pure perl, pluggable, lightweight web application framework

DEPRECATED=	depends on mod_perl 1 which is gone

BUILD_DEPENDS=	${PM_DEPENDS}
RUN_DEPENDS=	${PM_DEPENDS}

PM_DEPENDS=	${SITE_PERL}/Bundle/Sledge.pm:${PORTSDIR}/www/p5-Bundle-Sledge

PERL_CONFIGURE=	yes

MAN3=		Sledge.3 \
		Sledge::Doc::Hooks.3 \
		Sledge::Doc::Tutorial.3 \
		Sledge::Doc::Install.3 \
		Sledge::Doc::Overview.3 \
		Sledge::Doc::FAQ.3

.include <bsd.port.mk>
