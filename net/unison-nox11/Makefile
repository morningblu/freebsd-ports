# New ports collection makefile for:	net/unison-nox11
# Date created:				2008-09-05
# Whom:					bsam
#
# $FreeBSD$
#

PORTREVISION=	1
PKGNAMESUFFIX=	-nox11

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	A user-level file synchronization tool (without x11 stuff)

CONFLICTS=	unison-[0-9]* unison-devel-[0-9]*

OPTIONS_EXCLUDE=	X11
OPTIONS_DEFAULT=	DOCS
MASTERDIR=	${.CURDIR}/../unison

.include "${MASTERDIR}/Makefile"
