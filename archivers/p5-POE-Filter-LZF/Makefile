# New ports collection makefile for:	p5-POE-Filter-LZF
# Date created:		2006-09-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Filter-LZF
PORTVERSION=	1.6.8
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BINGOS
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A POE filter wrapped around Compress::LZF

BUILD_DEPENDS=	p5-Compress-LZF>=1.51:${PORTSDIR}/archivers/p5-Compress-LZF \
		p5-POE>=0.38:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	p5-Compress-LZF>=1.51:${PORTSDIR}/archivers/p5-Compress-LZF \
		p5-POE>=0.38:${PORTSDIR}/devel/p5-POE

PERL_CONFIGURE=	yes

MAN3=		POE::Filter::LZF.3

.include <bsd.port.mk>
