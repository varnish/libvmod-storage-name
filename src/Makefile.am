AM_CPPFLAGS = @VMOD_INCLUDES@ -Wall -Werror

vmoddir = @VMOD_DIR@
vmod_LTLIBRARIES = libvmod_storage_name.la

libvmod_storage_name_la_LDFLAGS = -module -export-dynamic -avoid-version -shared

libvmod_storage_name_la_SOURCES = \
	vmod_storage_name.c

nodist_libvmod_storage_name_la_SOURCES = \
	vcc_if.c \
	vcc_if.h

vmod_storage_name.lo: vcc_if.c vcc_if.h

vcc_if.c: vcc_if.h

vcc_if.h: @VMODTOOL@ $(top_srcdir)/src/vmod_storage_name.vcc
	@VMODTOOL@ $(top_srcdir)/src/vmod_storage_name.vcc

VMOD_TESTS = $(top_srcdir)/src/tests/*.vtc
.PHONY: $(VMOD_TESTS)

$(top_srcdir)/src/tests/*.vtc: libvmod_storage_name.la
	@VARNISHTEST@ -Dvarnishd=@VARNISHD@ -Dvmod_topbuild=$(abs_top_builddir) $@

check: $(VMOD_TESTS)

EXTRA_DIST = \
	vmod_storage_name.vcc \
	$(VMOD_TESTS)

CLEANFILES = \
	$(builddir)/vcc_if.c \
	$(builddir)/vcc_if.h \
	$(builddir)/vmod_storage_name.rst \
	$(builddir)/vmod_storage_name.man.rst
