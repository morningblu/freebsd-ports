# New ports collection makefile for:	devel/p5-Config-JFDI
# Date created:				29 Mar 2009
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Config-JFDI
PORTVERSION=	0.065
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ROKR
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Catalyst::Plugin::ConfigLoader-style layer over Config::Any

BUILD_DEPENDS=	\
	p5-Carp-Clan-Share>=0:${PORTSDIR}/devel/p5-Carp-Clan-Share \
	p5-Hash-Merge-Simple>=0:${PORTSDIR}/devel/p5-Hash-Merge-Simple \
	p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
	p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
	p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
	p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
	p5-Sub-Install>=0:${PORTSDIR}/devel/p5-Sub-Install \
	p5-Data-Visitor>=0.24:${PORTSDIR}/devel/p5-Data-Visitor
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most

PERL_CONFIGURE=	yes

MAN3=	Config::JFDI.3

post-extract:
	@${PERL} -i -ne 'print unless /\.swp$$/' ${WRKSRC}/MANIFEST
	@${PERL} -i.bak -ne 'print unless m,^Test::,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
