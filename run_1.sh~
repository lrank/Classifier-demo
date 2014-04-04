#select lines form source
#./splitline150 < nctest2007.en > nctest2007en.lines
#./splitline600 < nctest2007.en > nctest2007en600.lines
#./splitline150 < nctest2007cz.output.txt > nctest2007cz.lines
#./splitline150 < nctest2007de.output.txt > nctest2007de.lines
#./splitline150 < nctest2007es.output.txt > nctest2007es.lines
#./splitline150 < nctest2007fr.output.txt > nctest2007fr.lines
#./splitline150 < NewSentenceCand.txt > NewSentenceCand.txt.lines

#parsing
#../stanford-parser-full-2014-01-04/lexparser.sh nctest2007en.lines > nctest2007en.parse
#../stanford-parser-full-2014-01-04/lexparser.sh nctest2007en600.lines > nctest2007en600.parse
#../stanford-parser-full-2014-01-04/lexparser.sh nctest2007cz.lines > nctest2007cz.parse
#../stanford-parser-full-2014-01-04/lexparser.sh nctest2007de.lines > nctest2007de.parse
#../stanford-parser-full-2014-01-04/lexparser.sh nctest2007es.lines > nctest2007es.parse
#../stanford-parser-full-2014-01-04/lexparser.sh nctest2007fr.lines > nctest2007fr.parse

#../stanford-parser-full-2014-01-04/lexparser.sh NewSentence_ad.txt > a.parse

#parseFeatureExtract
#./parseFeatureExtract < nctest2007en.parse > nctest2007en.parse.out
#./parseFeatureExtract < nctest2007en600.parse > nctest2007en600.parse.out
#./parseFeatureExtract < nctest2007cz.parse > nctest2007cz.parse.out
#./parseFeatureExtract < nctest2007de.parse > nctest2007de.parse.out
#./parseFeatureExtract < nctest2007es.parse > nctest2007es.parse.out
#./parseFeatureExtract < nctest2007fr.parse > nctest2007fr.parse.out

./parseFeatureExtract < a.parse > a.parse.out

#training data
./featureextract < nctest2007en.parse.out > train_data
./featureextract_neg < nctest2007cz.parse.out >> train_data

#testing data
#./featureextract < nctest2007en600.parse.out > test.out
#./featureextract < nctest2007en.parse.out > test.out
#./featureextract_neg < nctest2007cz.parse.out >> test.out
#./featureextract_neg < nctest2007de.parse.out >> test.out
#./featureextract_neg < nctest2007es.parse.out >> test.out
#./featureextract_neg < nctest2007fr.parse.out >> test.out

./featureextract_neg < a.parse.out > test.out

#copy operation
cp train_data ../liblinear-1.94/train_data
cp test.out ../liblinear-1.94/test.out

