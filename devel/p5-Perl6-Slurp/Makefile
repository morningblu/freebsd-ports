# New ports collection makefile for:	p5-Perl6-Slurp
# Date created:		2011-11-05
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Perl6-Slurp
PORTVERSION=	0.05.1000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implements the Perl6 'slurp' built-in

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Perl6-Export>=0.07:${PORTSDIR}/devel/p5-Perl6-Export
RUN_DEPENDS=	p5-Perl6-Export>=0.07:${PORTSDIR}/devel/p5-Perl6-Export

PERL_CONFIGURE=	yes

MAN3=		Perl6::Slurp.3

.include <bsd.port.mk>
