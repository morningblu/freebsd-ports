# New ports collection makefile for:	ssh-copy-id
# Date created:				14 Jan 2011
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ssh-copy-id
PORTVERSION=	5.6p1
CATEGORIES=	security
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Small script which copies your ssh public-key to a remote host

NO_BUILD=	yes

MAN1=		ssh-copy-id.1
PLIST_FILES=	bin/ssh-copy-id

pre-patch:
.for f in ssh-copy-id ssh-copy-id.1
	@${CP} ${FILESDIR}/${f} ${WRKDIR}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
