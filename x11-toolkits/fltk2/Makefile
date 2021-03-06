# New ports collection makefile for:	fltk2
# Date created:				2006-03-26
# Whom:					Thomas-Martin Seck <tmseck@netcologne.de>
#
# $FreeBSD$
#

PORTNAME=	fltk
PORTVERSION=	2.0.${SNAPSHOT}
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_EASYSW}
MASTER_SITE_SUBDIR=	fltk/snapshots
DISTNAME=	fltk-2.0.x-alpha-${SNAPSHOT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast Light Toolkit version 2 (development snapshot)

LICENSE=	FLTK
LICENSE_GROUPS=	GPL
LICENSE_NAME=	FLTK License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

# XXX:
# FLTK2's configure script tries to find out whether the running X server
# supports overlay visuals; this is a bit difficult to find out if you
# are building in an environment where it cannot connect to an X server...
# If one wants to force a certain setting one needs to set ac_cv_have_overlay
# to "yes" or "no" in the configure environment. Since I am not sure whether
# this is desirable, leave this as is for now.
# If xprop cannot connect to an X server of if xprop cannot be found, X overlay
# support will be disabled without breaking the build.
BUILD_DEPENDS=	xprop:${PORTSDIR}/x11/xprop
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

SNAPSHOT=	r9166

OPTIONS_DEFINE=	THREADS CAIRO EXAMPLES XINERAMA DOCS
OPTIONS_DEFAULT=	THREADS XINERAMA
#OPTIONS=	THREADS "Install with threads support" on \
#		CAIRO "Use cairo as graphics backend" off \
#		EXAMPLES "Build and install example programs" on \
#		XINERAMA "Enable Xinerama support" on

EXAMPLESDIR=	${PREFIX}/share/examples/fltk2
LATEST_LINK=	fltk2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_XORG=	xcursor xft xi
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=	--enable-jpeg --enable-png --enable-gl --enable-xft \
			--enable-zlib
# Turn shared library support off for now since fltk2 is not yet stable.
# fltk2 applications should only be linked statically for now to avoid trouble
# after possibly incompatible updates to fltk2.
CONFIGURE_ARGS+=	--disable-shared

DOCSDIR=	${PREFIX}/share/doc/fltk2
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-threads
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

.if ${PORT_OPTIONS:MCAIRO}
CONFIGURE_ARGS+=	--enable-cairo
LIB_DEPENDS+=	cairo.2:${PORTSDIR}/graphics/cairo
# XXX:
# FLTK2's configure check currently depends on pkg-config being available...
BUILD_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkg-config
.else
CONFIGURE_ARGS+=	--disable-cairo
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
example_apps=	ansiwidget arc \
		bitmap boxtype browser button buttons \
		cairo callbacks checkers clock color_chooser cube \
		CubeView cursor curve \
		demo doublebuffer drawing drawtiming \
		editor exception \
		file_chooser fonts fractals fullscreen \
		gl_overlay glpuzzle \
		hello \
		image image_transform inactive input \
		keyboard \
		label line_style list list_visuals \
		mandelbrot menu message monitors \
		navigation \
		output \
		pack pixmap progress \
		qubix \
		radio resizable resizealign \
		scroll shape sizes subwindow symbols \
		tabs threads tile timer \
		utf \
		valuators wizard
example_data=	demo.menu
example_img=	images/ulon.bmp
PORTEXAMPLES=	*
.else
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-Makefile
.endif

.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=	xinerama
CONFIGURE_ARGS+=	--enable-xinerama
.else
CONFIGURE_ARGS+=	--disable-xinerama
.endif

post-patch:
	${REINPLACE_CMD} -e 's:%%CXX%%:${CXX}:g' \
	    ${WRKSRC}/fltk2-config.in \
	    ${WRKSRC}/makeinclude.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/documentation && ${INSTALL_DATA} *.html *.gif ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README_fltk1_to_fltk2.txt ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/images
	for f in ${example_apps} ; do \
	    ${INSTALL_PROGRAM} ${WRKSRC}/test/$${f} ${EXAMPLESDIR} ; \
	done
	for f in ${example_data} ; do \
	    ${INSTALL_DATA} ${WRKSRC}/test/$${f} ${EXAMPLESDIR} ; \
	done
	for f in ${example_img} ; do \
	    ${INSTALL_DATA} ${WRKSRC}/test/$${f} ${EXAMPLESDIR}/images ; \
	done
.endif

.include <bsd.port.mk>
