# New ports collection makefile for:    grouch
# Date created:         09 Sep 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	grouch
PORTVERSION=	20061120
CATEGORIES=	net-im gnustep
MASTER_SITES=	http://asveikau.ath.cx/projects/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AOL and ICQ Instant Messenger client for GNUstep

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_SYSTEM_LIBS+=	Renaissance:${RENAISSANCE_PORT}
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/Grouch

RENAISSANCE_PORT?=	x11-toolkits/renaissance

.include <bsd.port.mk>
