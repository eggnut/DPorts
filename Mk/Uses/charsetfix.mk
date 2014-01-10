# $FreeBSD: Mk/Uses/charsetfix.mk 338601 2014-01-04 00:02:08Z bapt $
#
# Lookup in Makefile.in to prevent a package from installing/modifying charset.alias
#
# MAINTAINER: portmgr@FreeBSD.org
#
# Feature:	charsetfix
# Usage:	USES=charsetfix
# Valid ARGS:	does not require args
#
#
.if !defined(_INCLUDE_USES_CHARSETFIX_MK)
_INCLUDE_USES_CHARSETFIX_MK=	yes

.if defined(charsetfix_ARGS)
IGNORE=	USES=charsetfix does not require args
.endif

CHARSETFIX_MAKEFILEIN?=	Makefile.in

charsetfix-post-patch:
	@${FIND} ${WRKSRC} -name "${CHARSETFIX_MAKEFILEIN}" -type f | ${XARGS} ${REINPLACE_CMD} \
		-e 's|need_charset_alias=true|need_charset_alias=false|g ; \
		s|test -f $$(charset_alias)|false|g ;\
		s|test -f $$(DESTDIR)$$(libdir)/charset.alias|false|g'

.endif
