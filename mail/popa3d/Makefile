# New ports collection makefile for:	popa3d
# Date created:		Sun Feb  6 12:31:29 MSK 2000
# Whom:			Sergey Samoyloff <gonza@techline.ru>
#
# $FreeBSD$
#

PORTNAME=	popa3d
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.openwall.com/popa3d/ \
		ftp://ftp.openwall.com/pub/projects/popa3d/
PKGNAMESUFFIX?=	${SMTP_AFTER_POP3_SUFFIX}${STANDALONE_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Secure, performance, tiny POP3 daemon

ALL_TARGET=	popa3d
MAN8=		popa3d.8
PLIST=		${WRKDIR}/.PLIST.more
CFLAGS+=	-DPREFIX=${PREFIX}
UNIQUENAME=	${.CURDIR:T}

OPTIONS?=	SMTP_AFTER_POP3 "Enable SMTP-after-POP mode" off \
		STANDALONE_POP3 "Enable standalone server mode" off \
		SETPROCTITLE "Enable setproctitle mode" off

.include <bsd.port.options.mk>

# honor old flags
.if defined(STANDALONE_POP3)
WITH_STANDALONE_POP3=	yes
.endif
.if defined(SMTP_AFTER_POP3)
WITH_SMTP_AFTER_POP3=	yes
.endif

.if defined(WITH_STANDALONE_POP3)
STANDALONE_SUFFIX=	-standalone
PLIST_SUB+=	STANDALONE_POP3=""
CONFLICTS?=	popa3d-0.* popa3d-before-sendmail-0.*
USE_RC_SUBR=	popa3d
PKGMESSAGE=	${NONEXISTENT}
PKGDEINSTALL=	${NONEXISTENT}
.else
SUB_FILES=	pkg-message
PLIST_SUB+=	STANDALONE_POP3="@comment "
.endif

.if defined(WITH_SMTP_AFTER_POP3)
SMTP_AFTER_POP3_SUFFIX=	-before-sendmail
EXTRA_PATCHES+=	${FILESDIR}/pop-before-sendmail.patch
PLIST_SUB+=	SMTP_AFTER_POP3=""
CONFLICTS?=	popa3d-0.* popa3d-standalone-0.*
.else
PLIST_SUB+=	SMTP_AFTER_POP3="@comment "
CONFLICTS?=	popa3d-standalone-0.* popa3d-before-sendmail-0.*
.endif

.if defined(WITH_SETPROCTITLE)
EXTRA_PATCHES+=	${FILESDIR}/setproctitle.patch
.endif

.include <bsd.port.pre.mk>

pre-configure:
	@${CAT} ${PKGDIR}/pkg-plist >${PLIST}
.if !exists(/var/empty)
	@${REINPLACE_CMD} -e "s=/var/empty=${PREFIX}/empty=" \
		${WRKSRC}/params.h
	@${ECHO_CMD} "@exec ${MKDIR} %D/empty" >>${PLIST}
	@${ECHO_CMD} "@dirrm empty" >>${PLIST}
.endif
.if defined(WITH_SMTP_AFTER_POP3) && !defined(WITHOUT_POPAUTH_M4)
	@${ECHO_CMD} "@cwd ${CFDIR}" >>${PLIST}
	@${ECHO_CMD} "hack/popauth.m4" >>${PLIST}
.endif
.if defined(WITH_STANDALONE_POP3)
	@${REINPLACE_CMD} -e 's|^\(#define POP_STANDALONE\).*|\1 1|' \
		${WRKSRC}/params.h
.endif
.if defined(MAILBOX_HOME)
	@${REINPLACE_CMD} -e 's|^#define \(MAIL_SPOOL_PATH\).*|#undef \1|' \
		${WRKSRC}/params.h
.endif

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.if !exists(/var/empty)
	@${MKDIR} ${PREFIX}/empty
.endif

do-install:
	${INSTALL} ${COPY} -o root -g wheel -m 500 \
	    ${WRKSRC}/popa3d ${PREFIX}/libexec/popa3d
	${INSTALL_MAN} ${WRKSRC}/popa3d.8 ${MANPREFIX}/man/man8/
.if defined(WITH_SMTP_AFTER_POP3) && !defined(WITHOUT_POPAUTH_M4)
	${INSTALL_DATA} ${FILESDIR}/popauth.m4 ${CFDIR}/hack/
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/DESIGN ${DOCSDIR}/
	${INSTALL_MAN} ${WRKSRC}/LICENSE ${DOCSDIR}/
.if defined(WITH_SMTP_AFTER_POP3)
	${INSTALL_DATA} ${FILESDIR}/POPAUTH ${DOCSDIR}/
.endif
.endif

.if !defined(WITH_STANDALONE_POP3)
post-install:
	@ ${CAT} ${PKGMESSAGE}
.endif

.if exists(${LOCALBASE}/share/sendmail/cf/mailer/uucp.m4)
CFDIR=		${LOCALBASE}/share/sendmail/cf
.else
CFDIR=		/usr/share/sendmail/cf
.endif

.include <bsd.port.post.mk>
