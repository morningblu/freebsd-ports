# New ports collection makefile for:	pecl-automap
# Date created:			21 Jan 2007
# Whom:				Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	automap
PORTVERSION=	1.1.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PECL extension offering a fast map-based autoloader

LICENSE=	PHP301

USE_PHP=	spl
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	automap
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5

CONFIGURE_ARGS=	--enable-automap

.include <bsd.port.mk>
