# New ports collection makefile for:	MooseX-Params-Validate
# Date created:	                        12 Aug 2009
# Whom:		                        Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Params-Validate
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An extension of Params::Validate for using Moose types

BUILD_DEPENDS=	p5-Moose>=0.74:${PORTSDIR}/devel/p5-Moose \
		p5-Params-Validate>0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Devel-Caller>0:${PORTSDIR}/devel/p5-Devel-Caller
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>0:${PORTSDIR}/devel/p5-Test-Fatal

PERL_CONFIGURE=	yes

MAN3=		MooseX::Params::Validate.3

.include <bsd.port.mk>
