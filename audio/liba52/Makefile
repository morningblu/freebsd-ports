# New ports collection makefile for:	liba52
# Date created:				Tue Oct 16 10:43:56 BRST 2001
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liba52
PORTVERSION=	0.7.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://liba52.sourceforge.net/files/
DISTNAME=	a52dec-${PORTVERSION:S/.b/b/}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A free library for decoding ATSC A/52 streams, aka AC-3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-oss --enable-shared
USE_LDCONFIG=	yes

.if !defined(WITHOUT_DJBFFT) && !defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdjbfft.a:${PORTSDIR}/math/djbfft
RUN_DEPENDS+=	${LOCALBASE}/lib/libdjbfft.a:${PORTSDIR}/math/djbfft

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--enable-djbfft
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "powerpc"
CFLAGS+=	-fPIC
.endif

MAN1=	a52dec.1 extract_a52.1

HEADER_FILES=	liba52/a52_internal.h

pre-everything::
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} ">>>"
	@${ECHO_MSG} ">>> You can enable extra optimizations by defining WITH_OPTIMIZED_CFLAGS."
	@${ECHO_MSG} ">>> For example, 'make WITH_OPTIMIZED_CFLAGS=yes'"
	@${ECHO_MSG} ">>>"
.endif
.ifndef(WITHOUT_DJBFFT)
	@${ECHO_MSG} '>>>'
	@${ECHO_MSG} '>>> You can disable djbfft optimized FFT routines by defining WITHOUT_DJBFFT.'
	@${ECHO_MSG} ">>> For example, 'make WITHOUT_DJBFFT=yes'"
	@${ECHO_MSG} '>>>'
.endif

post-patch:
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -E -e 's!-O3!${CFLAGS}!' -e 's!-mcpu=[^"]+"!"!' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
.ifndef(WITHOUT_DJBFFT)
	@${REINPLACE_CMD} -E -e 's|(fftc4.h)|djbfft/\1|' ${WRKSRC}/liba52/imdct.c
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/liba52.txt ${DOCSDIR}
.endif
.for file in ${HEADER_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include/a52dec
.endfor

.include <bsd.port.post.mk>
