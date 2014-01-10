# $FreeBSD: Mk/Uses/uidfix.mk 339195 2014-01-09 00:21:10Z bapt $
#
# Changes some default behaviour of build systems to allow installing as user.
#
# MAINTAINER:	bapt@FreeBSD.org
#
# Feature:	uidfix
# Usage:	USES=uidfix
# Valid ARGS:	none
#
.if !defined(_INCLUDE_USES_UIDFIX_MK)
_INCLUDE_USES_UIDFIX_MK=	yes
.if ${UID} != 0
.if !defined(GID)
GID!=	id -g
.endif
MAKE_ENV+=	BINOWN=${UID} SHAREOWN=${UID} CONFOWN=${UID} LIBOWN=${UID}
MAKE_ENV+=	BINGRP=${GID} SHAREGRP=${GID} CONFGRP=${GID} LIBGRP=${GID}
BINOWN=	${UID}
LIBOWN=	${UID}
SHAREOWN=	${UID}
WWWOWN=	${UID}
BINGRP=	${GID}
LIBGRP=	${GID}
SHAREGRP=	${GID}
WWWGRP=	${GID}
.endif
.endif
