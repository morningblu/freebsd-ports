# New ports collection makefile for:	p5-News-Article-NoCeM
# Date created:				10 December 2004
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	News-Article-NoCeM
PORTVERSION=	0.08
CATEGORIES=	news perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A module to generate accurate NoCeM notices

RUN_DEPENDS=	${SITE_PERL}/News/Article.pm:${PORTSDIR}/news/p5-News-Article \
		${SITE_PERL}/PGP/Sign.pm:${PORTSDIR}/security/p5-PGP-Sign
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		News::Article::NoCeM.3

.include <bsd.port.mk>
