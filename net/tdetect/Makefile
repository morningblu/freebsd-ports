# New ports collection makefile for:   tdetect
# Date created:			  Sun Jan 31, 1997
# Whom:               		  shipley@dis.org
#
# $FreeBSD$
#

PORTNAME=	tdetect
PORTVERSION=	0.2
CATEGORIES=	net
MASTER_SITES=	# disappeared

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for detecting traceroutes and reporting them via syslog

pre-configure:
	${REINPLACE_CMD} -e 's/trdetect/tdetect/g' ${WRKSRC}/config.h
	${REINPLACE_CMD} -e 's/LOG_AUTHPRIV/LOG_SECURITY/g' ${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tdetect ${PREFIX}/sbin/tdetect

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/tdetect.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/tdetect.sh startup file."; \
		${INSTALL_SCRIPT} -m 750 ${FILESDIR}/tdetect.sh ${PREFIX}/etc/rc.d/tdetect.sh; \
		${SED} -e 's,/usr/local,${PREFIX},g' ${PKGMESSAGE}; \
	fi

.include <bsd.port.mk>
