# New ports collection makefile for:	kyotocabinet-ruby
# Date created:		28 April 2010
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	kyotocabinet
PORTVERSION=	1.24
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	http://fallabs.com/kyotocabinet/rubypkg/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby (1.9.1+) binding to Kyoto Cabinet

LIB_DEPENDS=	kyotocabinet:${PORTSDIR}/databases/kyotocabinet

LICENSE=	GPLv3

DEPRECATED=	BROKEN for more than 6 month
EXPIRATION_DATE=	2012-05-10

BROKEN=	does not compile

RUBY_VER=	1.9
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

NO_PACKAGE=	GPL3 incompatibility with Ruby

CONFIGURE_ARGS=	--with-kyotocabinet-dir="${LOCALBASE}" \
		--with-bindir="${LOCALBASE}/bin"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
BROKEN=		requires gcc 4.2+ and ruby built with the same compiler
.endif

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/kyotocabinet.so

.if !defined(NOPORTDOCS)
DOCSDIR=	${RUBY_MODDOCDIR}
PORTDOCS=	*
.endif
.if !defined(NOPORTEXAMPLES)
EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}
PORTEXAMPLES=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

check:
	cd ${BUILD_WRKSRC} && ${SETENV} RUBYLIB=. ${RUBY} test.rb

.include <bsd.port.post.mk>
