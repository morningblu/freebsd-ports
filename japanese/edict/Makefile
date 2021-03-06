# New ports collection makefile for:	edict
# Date created:		18 August 1997
# Whom:			Jonathan Hanna
#
# $FreeBSD$
#

PORTNAME=	edict
PORTVERSION=	19990714
PORTREVISION=	5
CATEGORIES=	japanese
MASTER_SITES=	\
		http://japanology.arts.kuleuven.ac.be/mirrors/monash/ \
		http://www.bcit-broadcast.com/monash/ \
		ftp://ftp.mirrorservice.org/sites/ftp.cc.monash.edu.au/pub/nihongo/ \
		ftp://ftp.edrdg.org/pub/Nihongo/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/nihongo/ftp.cc.monash.edu.au/ \
		ftp://ftp.funet.fi/pub/culture/japan/mirrors/monash/pub/nihongo/ \
		ftp://ftp.uni-duisburg.de/Mirrors/ftp.monash.edu.au/pub/nihongo/ \
		ftp://ftp.monash.edu.au/pub/nihongo/
EXTRACT_SUFX=
DISTFILES=	${DICTFILES} ${SRCFILES} ${DOCFILES}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese-English dictionaries with access and maintenance utilities

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

DIST_SUBDIR=	edict

DICTFILES=	edict.gz edicth enamdict.gz compdic.gz \
		j_places.gz ediclsd3.zip \
		kanjidic.gz kanjd212.gz lawgledt.zip \
		lingdic.zip geodic.gz pandpdic.zip \
		aviation.zip findic.zip mktdic.zip \
		4jword3_edict.zip concrete.zip

SRCFILES=	xjdic23.tgz

DOCFILES=	edict_doc.html edicth.doc \
		enamdict_doc.txt enamdict_doc.html \
		j_places.inf kanjidic.doc kanjd212.doc ediclsd3.rme \
		lawgldoc.new lingdic.txt geodic.doc aviation.txt \
		findic.doc mktdic.doc 4jword3_inf.txt \
		concrete.doc

#
# These change too often and are not made into executables.
#
IGNOREFILES=	${DICTFILES} ${DOCFILES}

BINFILES=	exjdxgen xjdic_cl xjdic_sa xjdserver xjdxgen

# Where to install the data files
DATADIR=	${PREFIX}/share/dict/edict
DOCSDIR=	${PREFIX}/share/doc/xjdic
MAN1=		xjdic.1

NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Fails to install on sparc64 with error 2
.endif

post-patch:
	@${GREP} -l '^main' ${WRKSRC}/*.c | ${XARGS} ${REINPLACE_CMD} \
		-e '/argv/s/unsigned//'

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@for _file in ${SRCFILES}; do \
		if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$${_file} ${EXTRACT_AFTER_ARGS});\
		then \
			exit 1; \
		fi \
	done

do-install:
	@for _file in ${BINFILES}; do \
		if ! ${INSTALL_PROGRAM} ${WRKDIR}/$${_file} ${PREFIX}/bin ;\
		then \
			exit 1; \
		fi \
	done
	@if [ ! -d ${DATADIR} ] ; \
	then \
		${MKDIR} ${DATADIR} ; \
	fi
	@for _file in ${DICTFILES}; do \
		case $${_file} in \
		*.gz) \
			instfile=`${BASENAME} $${_file} .gz` ; \
			if ${GZIP_CMD} -cd ${_DISTDIR}/$${_file} > ${DATADIR}/$$instfile ; \
			then \
				${TRUE} ; \
			else \
				exit 1; \
			fi \
			;; \
		*.Z) \
			instfile=`${BASENAME} $$file .Z` ; \
			if ${GZIP_CMD} -cd ${_DISTDIR}/$${_file} > ${DATADIR}/$$instfile ; \
			then \
				${TRUE} ; \
			else \
				exit 1; \
			fi \
			;; \
		*.zip) \
			instfile=`${BASENAME} $${_file} .zip` ; \
			if [ $$instfile = 4jword3_edict ] ; \
			then \
				instfile=4jword3_edict.euc ; \
			fi; \
			if ${UNZIP_CMD} -o ${_DISTDIR}/$${_file} $$instfile -d ${DATADIR} ; \
			then \
				${TRUE} ; \
			else \
				exit 1; \
			fi \
			;; \
		*) \
			instfile=`${BASENAME} $${_file}` ; \
			${CP} ${_DISTDIR}/$${_file} ${DATADIR} ; \
			;; \
		esac ; \
		( \
			${ECHO} cd ${DATADIR} ; \
			cd ${DATADIR} ; \
			${ECHO} ${PREFIX}/bin/xjdxgen $$instfile ; \
			${PREFIX}/bin/xjdxgen $$instfile ; \
			${CHOWN} ${SHAREOWN}:${SHAREGRP} $$instfile $$instfile.xjdx; \
			${CHMOD} ${SHAREMODE} $$instfile $$instfile.xjdx ; \
		) ; \
	done
	${RM} -f ${PREFIX}/bin/xjdic
	${LN} -s ${PREFIX}/bin/xjdic_sa ${PREFIX}/bin/xjdic
	${INSTALL_DATA} ${WRKDIR}/radicals.tm ${DATADIR} ;
	${INSTALL_DATA} ${WRKDIR}/radkfile ${DATADIR} ;
	${INSTALL_DATA} ${WRKDIR}/kanjstroke ${DATADIR} ;
	${INSTALL_DATA} ${WRKDIR}/romkana.cnv ${DATADIR} ;
	${INSTALL_DATA} ${WRKDIR}/vconj ${DATADIR} ;
	#
	# Only 9 dictionaries can be enabled
	#
	@${ECHO_CMD} dicdir ${DATADIR} > ${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile edict >> ${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile enamdict >> ${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile compdic >> ${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile ediclsd3 >> ${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile j_places >> ${DATADIR}/.xjdicrc
	# @${ECHO_CMD} dicfile lawgledt >> ${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile geodic >> ${DATADIR}/.xjdicrc
	# @${ECHO_CMD} dicfile pandpdic >> ${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile aviation >> ${DATADIR}/.xjdicrc
	# @${ECHO_CMD} dicfile findic >> ${DATADIR}/.xjdicrc
	# @${ECHO_CMD} dicfile mktdic >> ${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile 4jword3_edict.euc >> ${DATADIR}/.xjdicrc
	# @${ECHO_CMD} dicfile concrete.doc >> ${DATADIR}/.xjdicrc
	# @${ECHO_CMD} dicfile lingdic >> ${DATADIR}/.xjdicrc
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DATADIR}/.xjdicrc
	@${CHMOD} ${SHAREMODE} ${DATADIR}/.xjdicrc
	${INSTALL_MAN} ${WRKSRC}/xjdic.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@if [ ! -d ${DOCSDIR} ] ; \
	then \
		${MKDIR} ${DOCSDIR} ; \
	fi
	${INSTALL_MAN} ${WRKSRC}/xjdic23.inf ${DOCSDIR}
	@for docfile in ${DOCFILES} ; do \
		${ECHO_CMD} Installing  ${DOCSDIR}/$${docfile} ; \
		${INSTALL_MAN}  ${_DISTDIR}/$${docfile} ${DOCSDIR} ; \
	done
.endif

.include <bsd.port.post.mk>
