# New ports collection makefile for:	Log::Any::Adapter::Dispatch
# Date created:		30 Aug 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Log-Any-Adapter-Dispatch
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for adapter to use Log::Dispatch with Log::Any

RUN_DEPENDS=	\
	p5-Log-Any-Adapter>0:${PORTSDIR}/devel/p5-Log-Any-Adapter \
	p5-Log-Dispatch>=2.26:${PORTSDIR}/devel/p5-Log-Dispatch
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Log::Any::Adapter::Dispatch.3

.include <bsd.port.mk>
