#!/usr/bin/perl
<>;
my %h;
my $i;
my @keys;
while (my $s = <>) {
	chomp $s;
	my ($suf) = $s =~ /\.(.+?)$/;
	push @keys, $suf unless exists $h{$suf};
	++$h{$suf};
}
foreach my $key (@keys) {
	print $key, ": ", $h{$key}, "\n";
}
