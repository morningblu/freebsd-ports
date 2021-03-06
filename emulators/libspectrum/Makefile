# New ports collection makefile for:	libspectrum
# Date created:			2003-10-27
# Whom:				Alexey V. Antipovsky <kemm@in-line.ru>
#
# $FreeBSD$
#

PORTNAME=	libspectrum
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	emulators devel
MASTER_SITES=	SF/fuse-emulator/${PORTNAME}/${PORTVERSION}

MAINTAINER=	yuri.pankov@gmail.com
COMMENT=	Handling of ZX-Spectrum emulator files formats

LIB_DEPENDS=	gcrypt.18:${PORTSDIR}/security/libgcrypt

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes

MAN3=		libspectrum.3

OPTIONS=	AUDIOFILE "Support loading from .wav files" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_AUDIOFILE)
LIB_DEPENDS+=	audiofile.0:${PORTSDIR}/audio/libaudiofile
.else
CONFIGURE_ARGS+=--without-libaudiofile
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} \
		AUTHORS ChangeLog README THANKS doc/libspectrum.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
