# New ports collection makefile for:	Tie::DNS
# Date created:				25 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Tie-DNS
PORTVERSION=	0.6.1
PORTEPOCH=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tie interface to p5-Net-DNS

RUN_DEPENDS=	p5-Net-DNS>=0.12:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Tie-Cache>=0.01:${PORTSDIR}/devel/p5-Tie-Cache
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Tie::DNS.3

.if !defined(NOPORTEXAMPLES)

PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/eg/* ${EXAMPLESDIR}

.endif

.include <bsd.port.mk>
