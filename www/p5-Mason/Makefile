# New ports collection makefile for:	Mason
# Date created:				03 April, 2012
# Whom:					Muhammad Moinur Rahman <5u623l20@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Mason
PORTVERSION=	2.17
CATEGORIES=	www perl5
MASTER_SITES=	CPAN/../by-authors/id/J/JS/JSWARTZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	High-performance, dynamic web site authoring system

BUILD_DEPENDS=	p5-Capture-Tiny>0:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Class-Unload>0:${PORTSDIR}/devel/p5-Class-Unload \
		p5-Devel-GlobalDestruction>0:${PORTSDIR}/devel/p5-Devel-GlobalDestruction \
		p5-Guard>1:${PORTSDIR}/devel/p5-Guard \
		p5-IPC-System-Simple>1:${PORTSDIR}/devel/p5-IPC-System-Simple \
		p5-JSON>2:${PORTSDIR}/converters/p5-JSON \
		p5-Method-Signatures-Simple>1:${PORTSDIR}/devel/p5-Method-Signatures-Simple \
		p5-Moose>2:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-StrictConstructor>=0.13:${PORTSDIR}/devel/p5-MooseX-StrictConstructor \
		p5-Exception-Class>1:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Log-Any>0:${PORTSDIR}/devel/p5-Log-Any \
		p5-MooseX-HasDefaults>0:${PORTSDIR}/devel/p5-MooseX-HasDefaults \
		p5-Test-Class-Most>0:${PORTSDIR}/devel/p5-Test-Class-Most \
		p5-Test-LongString>0:${PORTSDIR}/devel/p5-Test-LongString

PERL_CONFIGURE=	yes

MAN3=		Mason::Manual::Filters.3 \
		Mason::Plugin::LvalueAttributes.3 \
		Mason::Manual::RequestDispatch.3 \
		Mason::PluginBundle::Default.3 \
		Mason::Component::ClassMeta.3 \
		Mason::Exceptions.3 \
		Mason::Manual::UpgradingFromMason1.3 \
		Mason::Manual::Tutorial.3 \
		Mason.3 \
		Mason::PluginRole.3 \
		Mason::Plugin::Defer.3 \
		Mason::Component.3 \
		Mason::Manual::Components.3 \
		Mason::Manual::Syntax.3 \
		Mason::Manual::FAQ.3 \
		Mason::Plugin::DollarDot.3 \
		Mason::Manual::Admin.3 \
		Mason::Manual::Cookbook.3 \
		Mason::Moose.3 \
		Mason::Compilation.3 \
		Mason::Component::Moose.3 \
		Mason::Moose::Role.3 \
		Mason::App.3 \
		Mason::Result.3 \
		Mason::Component::Import.3 \
		Mason::Filters::Standard.3 \
		Mason::Plugin::TidyObjectFiles.3 \
		Mason::Manual.3 \
		Mason::Manual::Intro.3 \
		Mason::CodeCache.3 \
		Mason::Manual::Subclasses.3 \
		Mason::Interp.3 \
		Mason::Manual::Plugins.3 \
		Mason::Request.3

.include <bsd.port.mk>
