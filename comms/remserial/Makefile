# New ports collection makefile for:	remserial
# Date created:				05 Jan 2011
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	remserial
PORTVERSION=	1.4
CATEGORIES=	comms
MASTER_SITES=	http://lpccomp.bc.ca/remserial/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Bridge between a TCP/IP network port and a character-oriented device

USE_DOS2UNIX=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/remserial
PORTDOCS=	README.txt

CFLAGS+=	-DOSVERSION=\"${OSVERSION}\"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
