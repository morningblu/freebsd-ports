# New ports collection makefile for:	Parallel::Scoreboard
# Date created:		31 Dec 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Parallel-Scoreboard
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of scoreboard for monitoring status of many workers

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>=0.05:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
	p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser \
	p5-JSON>0:${PORTSDIR}/converters/p5-JSON
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Parallel::Scoreboard.3 \
	Parallel::Scoreboard::PSGI::App.3 \
	Parallel::Scoreboard::PSGI::App::JSON.3

.include <bsd.port.mk>
