# New ports collection makefile for:	py-pytest
# Date created:				15 July 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	pytest
PORTVERSION=	2.2.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Cross-project testing tool for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylib>=1.4.8:${PORTSDIR}/devel/py-pylib

PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}
# Python 3 ready
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes

.include <bsd.port.mk>
