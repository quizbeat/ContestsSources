#!/usr/bin/perl
my $str =  <>;
my @a = $str =~ /\!/g;
my $n = scalar(@a);
if ($n == 0) {
	print "Pfff";
}
else {
	print "W"."o"x$n."w";
}