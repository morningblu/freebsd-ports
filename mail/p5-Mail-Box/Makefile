# New ports collection makefile for:	Mail-Box
# Date created:				Wed Jan  3 12:54:59 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Mail-Box
PORTVERSION=	2.105
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module implementing a modern mail folder management

COMMON_DEPENDS=	\
	p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
	p5-MIME-Types>=0:${PORTSDIR}/mail/p5-MIME-Types \
	p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
	p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
	p5-File-Remove>=0.20:${PORTSDIR}/devel/p5-File-Remove \
	p5-HTML-Format>=2.01:${PORTSDIR}/textproc/p5-HTML-Format \
	p5-HTML-Tree>=3.13:${PORTSDIR}/www/p5-HTML-Tree \
	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
	p5-Mail-IMAPClient>=2.2.8:${PORTSDIR}/mail/p5-Mail-IMAPClient \
	p5-Mail-Transport-Dbx>=0.04:${PORTSDIR}/mail/p5-Mail-Transport-Dbx \
	p5-Object-Realize-Later>=0.14:${PORTSDIR}/devel/p5-Object-Realize-Later \
	p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
	p5-URI>=1.23:${PORTSDIR}/net/p5-URI \
	p5-User-Identity>=0.90:${PORTSDIR}/devel/p5-User-Identity
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1.00:${PORTSDIR}/devel/p5-Test-Pod

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	</dev/null
CONFIGURE_ENV+=	MAILBOX_INSTALL_OPTIONALS=n

.include "Makefile.man"
.include <bsd.port.pre.mk>

# One of it's dependency is p5-GSSAPI which is marked broken for 7.X
.if ${OSVERSION} < 800000
BROKEN=	Does not work on FreeBSD 7.x
.endif

.include <bsd.port.post.mk>
