# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	imlib2
PORTVERSION=	1.5.0
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	SF/enlightenment/imlib2-src/${PORTVERSION}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	The next generation graphics library for Enlightenment

LICENSE=	imlib2
LICENSE_NAME=	imlib2 license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libfreetype.so:print/freetype2

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pathfix pkgconfig tar:bzip2

CONFIGURE_ARGS=	--enable-visibility-hiding --disable-static \
		--with-zlib --with-bzip2
CONFIGURE_ENV=	ac_cv_lib_dl_dlopen=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	JPEG PNG TIFF GIF ID3 X11
OPTIONS_DEFAULT=	JPEG PNG TIFF GIF ID3 X11
OPTIONS_SUB=	yes

X11_USE=		XORG=x11,sm,xcb,xext
X11_CONFIGURE_ON=	--with-x --with-x-shm-fd
X11_CONFIGURE_OFF=	--without-x --without-x-shm-fd

JPEG_USES=		jpeg
JPEG_CONFIGURE_ON=	--with-jpeg
JPEG_CONFIGURE_OFF=	--without-jpeg

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_ON=	--with-png
PNG_CONFIGURE_OFF=	--without-png

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_ON=	--with-tiff
TIFF_CONFIGURE_OFF=	--without-tiff

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CONFIGURE_ON=	--with-gif
GIF_CONFIGURE_OFF=	--without-gif

ID3_LIB_DEPENDS=	libid3tag.so:audio/libid3tag
ID3_CONFIGURE_ON=	--with-id3
ID3_CONFIGURE_OFF=	--without-id3

.include <bsd.port.options.mk>

.if ${ARCH} == "i386" && !empty(MACHINE_CPU:Mmmx)
CONFIGURE_ARGS+=	--enable-mmx
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif

.if ${ARCH} == "x86_64"
CONFIGURE_ARGS+=	--enable-amd64
.else
CONFIGURE_ARGS+=	--disable-amd64
.endif

post-patch-X11-off:
	@${REINPLACE_CMD} -e '/MY_LIBS =/s/-lXext -lX11//' \
		${WRKSRC}/src/lib/Makefile.in
	@${REINPLACE_CMD} -e '/#ifndef X_DISPLAY_MISSING/,/#endif/ d' \
		${WRKSRC}/src/lib/Imlib2.h

.include <bsd.port.mk>
