# New ports collection makefile for:	textproc/p5-RTF-Parser
# Date created:				Oct 15th 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	RTF-Parser
PORTVERSION=	1.09
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for parsing RTF files

BUILD_DEPENDS=	p5-RTF-Tokenizer>=0:${PORTSDIR}/textproc/p5-RTF-Tokenizer
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		RTF::HTML::Converter.3 \
		RTF::Control.3 \
		RTF::TEXT::Converter.3 \
		RTF::Parser.3

.include <bsd.port.mk>
