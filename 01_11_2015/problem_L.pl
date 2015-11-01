#!/usr/bin/perl
my %h;
while (my $str = <>) {
	chomp $str;
	++$h{join "", sort {$a <=> $b} split " ", $str};
}
print scalar(keys(%h));