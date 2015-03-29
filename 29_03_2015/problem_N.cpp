#!/usr/bin/perl
<>;
my %h;
my $max = 0;
while($a=<>) {
	++$h{$a};
	if ($max < $h{$a}) {
		$max = $h{$a};
	}
}
my @m = %h;
my @r;
while(($a = shift @m, $b = shift @m)) {
	if ($b == $max) {
		$a =~ s/\n//;
		push @r, $a;
	}
}
print join "\n", sort @r;
