# New ports collection makefile for:	spass
# Date created:        			27 October 2010
# Whom:					Eitan Adler <eadler@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spass
PORTVERSION=	2.0
CATEGORIES=	security
MASTER_SITES=	http://www.guyrutenberg.com/wp-content/uploads/2010/08/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	A secure password generator with a true random number generator

LIB_DEPENDS=	boost_program_options:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_BZIP2=	yes

PLIST_FILES=	bin/spass

.include <bsd.port.mk>
