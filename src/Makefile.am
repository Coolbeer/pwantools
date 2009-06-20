bin_PROGRAMS = pwantools
pwantools_SOURCES = \
	main.cpp \
	pwanutils.cpp \
	pwanoptions.cpp \
	pwanpck.cpp \
	pwanstrings.cpp \
	pwandebug.cpp \
	pwandir.cpp \
	pwanfileinfo.cpp \
	pwancmdlineparser.cpp

CLEANFILES = *moc *~

AM_CXXFLAGS = $(BOOST_CPPFLAGS)
AM_LDFLAGS =  $(BOOST_LDFLAGS) $(BOOST_FILESYSTEM_LIB)
