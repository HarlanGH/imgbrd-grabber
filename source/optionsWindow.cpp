#include <QApplication>
#include "optionsWindow.h"
#include "mainWindow.h"

using namespace std;



optionsWindow::optionsWindow(mainWindow *parent) : QWidget(parent), parent(parent)
{
	this->setWindowIcon(QIcon(":/images/icon.ico"));
	this->setWindowTitle(tr("Grabber")+" - "+tr("Options"));
	this->setWindowFlags(Qt::Window);
	
	QSettings settings("settings.ini", QSettings::IniFormat);
	QStringList languages = QStringList() << "English" << "Fran�ais";
	QStringList codes = QStringList() << "en" << "fr";
	
	QTabWidget *onglets = new QTabWidget(this);
	
	QWidget *page0 = new QWidget;
		QComboBox *comboLanguages = new QComboBox;
			comboLanguages->setMaxVisibleItems(20);
			comboLanguages->addItems(languages);
			comboLanguages->setCurrentIndex(codes.indexOf(settings.value("language", "en").toString()));
		QLineEdit *lineBlacklistedtags = new QLineEdit;
			lineBlacklistedtags->setText(settings.value("blacklistedtags").toString());
		QCheckBox *checkDownloadBlacklist = new QCheckBox;
			checkDownloadBlacklist->setChecked(settings.value("downloadblacklist").toBool());
		QLabel *txt_1 = new QLabel(tr("<i>Une confirmation sera demand�e avant l'affichage d'une image contenant un tag contenu dans cette liste (s�parer les tags par des espaces).</i>"));
			txt_1->setWordWrap(true);
		QSpinBox *spinColumns = new QSpinBox;
			spinColumns->setRange(1, 4);
			spinColumns->setValue(settings.value("columns", 1).toInt());
	QFormLayout *form0 = new QFormLayout;
		form0->addRow(tr("&Langue"), comboLanguages);
		form0->addRow(tr("&Liste noire"), lineBlacklistedtags);
		form0->addRow(txt_1);
		form0->addRow(tr("&T�l�charger les image de la liste noire"), checkDownloadBlacklist);
		form0->addRow(tr("&Nombre de colonnes"), spinColumns);
	page0->setLayout(form0);
	onglets->addTab(page0, tr("G�n�ral"));
	
	QStringList sources = QStringList() << "xml" << "json" << "regex";
	QWidget *page01 = new QWidget;
		QSpinBox *spinLimit = new QSpinBox;
			spinLimit->setRange(1, 100);
			spinLimit->setValue(settings.value("limit", 20).toInt());
		QComboBox *comboSource1 = new QComboBox;
			comboSource1->setMaxVisibleItems(20);
			comboSource1->addItems(sources);
			comboSource1->setCurrentIndex(sources.indexOf(settings.value("source_1", "xml").toString()));
		QComboBox *comboSource2 = new QComboBox;
			comboSource2->setMaxVisibleItems(20);
			comboSource2->addItems(sources);
			comboSource2->setCurrentIndex(sources.indexOf(settings.value("source_2", "json").toString()));
		QComboBox *comboSource3 = new QComboBox;
			comboSource3->setMaxVisibleItems(20);
			comboSource3->addItems(sources);
			comboSource3->setCurrentIndex(sources.indexOf(settings.value("source_3", "regex").toString()));
	QFormLayout *form01 = new QFormLayout;
		form01->addRow(tr("&Images par page"), spinLimit);
		form01->addRow(tr("&Source 1"), comboSource1);
		form01->addRow(tr("&Source 2"), comboSource2);
		form01->addRow(tr("&Source 3"), comboSource3);
	page01->setLayout(form01);
	onglets->addTab(page01, tr("Sources"));

	settings.beginGroup("Save");
	QWidget *page1 = new QWidget;
		QLineEdit *linePath = new QLineEdit;
			linePath->setText(settings.value("path").toString());
		QLineEdit *lineFilename = new QLineEdit;
			lineFilename->setText(settings.value("filename").toString());
		QLabel *txt_3 = new QLabel(tr(
			"Symboles disponibles : <i>%artist%</i>, <i>%general%</i>, <i>%copyright%</i>, <i>%character%</i>, <i>%all%</i>, <i>%filename%</i>, <i>%ext%</i>, <i>%rating%</i>, <i>%website%</i>, <i>%md5%</i>."
			"<br/><i>%artist%</i> : tags de nom d'artiste"
			"<br/><i>%general%</i> : tags d'image g�n�riques"
			"<br/><i>%copyright%</i> : tags de copyright, en g�n�ral le nom de l'anime/manga"
			"<br/><i>%character%</i> : tags indiquant quels personnages sont pr�sents sur l'image"
			"<br/><i>%all%</i> : tous les tags"
			"<br/><i>%filename%</i> : nom du fichier sur le serveur, en g�n�ral une cha�ne alphanum�rique"
			"<br/><i>%ext%</i> : extension de l'image"
			"<br/><i>%rating%</i> : Questionable, Safe ou Explicit"
			"<br/><i>%website%</i> : url du site de l'image"
			"<br/><i>%md5%</i> : code unique de l'image, compos� de 32 caract�res alphanum�riques"
		));
			txt_3->setWordWrap(true);
	QFormLayout *form1 = new QFormLayout;
		form1->addRow(tr("&Dossier"), linePath);
		form1->addRow(tr("&Format"), lineFilename);
		form1->addRow(txt_3);
	page1->setLayout(form1);
	onglets->addTab(page1, tr("Sauvegarde"));
		
	QWidget *page2 = new QWidget;
		QLineEdit *lineArtistEmpty = new QLineEdit;
			lineArtistEmpty->setText(settings.value("artist_empty", "anonymous").toString());
		QCheckBox *checkArtistUseall = new QCheckBox;
			checkArtistUseall->setChecked(settings.value("artist_useall", false).toBool());
		QLineEdit *lineArtistSep = new QLineEdit;
			lineArtistSep->setText(settings.value("artist_sep", "+").toString());
		QLineEdit *lineArtistValue = new QLineEdit;
			lineArtistValue->setText(settings.value("artist_value", "multiple artists").toString());
	QFormLayout *form2 = new QFormLayout;
		form2->addRow(tr("Si &aucun"), lineArtistEmpty);
		form2->addRow(tr("&Garder tous"), checkArtistUseall);
		form2->addRow(tr("&S�parateur si multiples"), lineArtistSep);
		form2->addRow(tr("&Valeur si multiples"), lineArtistValue);
	page2->setLayout(form2);
	onglets->addTab(page2, tr("Tags artiste"));
		
	QWidget *page3 = new QWidget;
		QLineEdit *lineCopyrightEmpty = new QLineEdit;
			lineCopyrightEmpty->setText(settings.value("copyright_empty", "misc").toString());
		QCheckBox *checkCopyrightUseall = new QCheckBox;
			checkCopyrightUseall->setChecked(settings.value("copyright_useall", false).toBool());
		QLineEdit *lineCopyrightSep = new QLineEdit;
			lineCopyrightSep->setText(settings.value("copyright_sep", "+").toString());
		QLineEdit *lineCopyrightValue = new QLineEdit;
			lineCopyrightValue->setText(settings.value("copyright_value", "crossover").toString());
	QFormLayout *form3 = new QFormLayout;
		form3->addRow(tr("Si &aucun"), lineCopyrightEmpty);
		form3->addRow(tr("&Garder tous"), checkCopyrightUseall);
		form3->addRow(tr("&S�parateur si multiples"), lineCopyrightSep);
		form3->addRow(tr("&Valeur si multiples"), lineCopyrightValue);
	page3->setLayout(form3);
	onglets->addTab(page3, tr("Tags s�rie"));
		
	QWidget *page4 = new QWidget;
		QLineEdit *lineCharacterEmpty = new QLineEdit;
			lineCharacterEmpty->setText(settings.value("character_empty", "unknown").toString());
		QCheckBox *checkCharacterUseall = new QCheckBox;
			checkCharacterUseall->setChecked(settings.value("character_useall", false).toBool());
		QLineEdit *lineCharacterSep = new QLineEdit;
			lineCharacterSep->setText(settings.value("character_sep", "+").toString());
		QLineEdit *lineCharacterValue = new QLineEdit;
			lineCharacterValue->setText(settings.value("character_value", "group").toString());
	QFormLayout *form4 = new QFormLayout;
		form4->addRow(tr("Si &aucun"), lineCharacterEmpty);
		form4->addRow(tr("&Garder tous"), checkCharacterUseall);
		form4->addRow(tr("&S�parateur si multiples"), lineCharacterSep);
		form4->addRow(tr("&Valeur si multiples"), lineCharacterValue);
	page4->setLayout(form4);
	onglets->addTab(page4, tr("Tags personnage"));
	settings.endGroup();
	
	QPushButton *backButton = new QPushButton(tr("Annuler"));
		connect(backButton, SIGNAL(clicked()), this, SLOT(close()));
	QPushButton *okButton = new QPushButton(tr("Ok"));
		connect(okButton, SIGNAL(clicked()), this, SLOT(save()));
	QGridLayout *l = new QGridLayout();
		l->addWidget(onglets, 0, 0, 1, 2);
		l->addWidget(backButton, 1, 0, 1, 1);
		l->addWidget(okButton, 1, 1, 1, 1);
	this->setLayout(l);
	
	this->languages = languages;
	this->codes = codes;
	this->sources = sources;
	this->comboLanguages = comboLanguages;
	this->lineBlacklistedtags = lineBlacklistedtags;
	this->checkDownloadBlacklist = checkDownloadBlacklist;
	this->spinColumns = spinColumns;
	this->spinLimit = spinLimit;
	this->comboSource1 = comboSource1;
	this->comboSource2 = comboSource2;
	this->comboSource3 = comboSource3;
	this->linePath = linePath;
	this->lineFilename = lineFilename;
	this->lineArtistEmpty = lineArtistEmpty;
	this->checkArtistUseall = checkArtistUseall;
	this->lineArtistSep = lineArtistSep;
	this->lineArtistValue = lineArtistValue;
	this->lineCopyrightEmpty = lineCopyrightEmpty;
	this->checkCopyrightUseall = checkCopyrightUseall;
	this->lineCopyrightSep = lineCopyrightSep;
	this->lineCopyrightValue = lineCopyrightValue;
	this->lineCharacterEmpty = lineCharacterEmpty;
	this->checkCharacterUseall = checkCharacterUseall;
	this->lineCharacterSep = lineCharacterSep;
	this->lineCharacterValue = lineCharacterValue;
	
	this->resize(QSize(600, 400));
}



void optionsWindow::save()
{
	QSettings settings("settings.ini", QSettings::IniFormat);
	settings.setValue("blacklistedtags", this->lineBlacklistedtags->text());
	settings.setValue("downloadblacklist", this->checkDownloadBlacklist->isChecked());
	settings.setValue("columns", this->spinColumns->value());
	settings.setValue("limit", this->spinLimit->value());
	settings.setValue("source_1", this->sources.at(this->comboSource1->currentIndex()));
	settings.setValue("source_2", this->sources.at(this->comboSource2->currentIndex()));
	settings.setValue("source_3", this->sources.at(this->comboSource3->currentIndex()));
	settings.beginGroup("Save");
		settings.setValue("path", this->linePath->text());
		settings.setValue("filename", this->lineFilename->text());
		settings.setValue("artist_empty", this->lineArtistEmpty->text());
		settings.setValue("artist_useall", this->checkArtistUseall->isChecked());
		settings.setValue("artist_sep", this->lineArtistSep->text());
		settings.setValue("artist_value", this->lineArtistValue->text());
		settings.setValue("copyright_empty", this->lineCopyrightEmpty->text());
		settings.setValue("copyright_useall", this->checkCopyrightUseall->isChecked());
		settings.setValue("copyright_sep", this->lineCopyrightSep->text());
		settings.setValue("copyright_value", this->lineCopyrightValue->text());
		settings.setValue("character_empty", this->lineCharacterEmpty->text());
		settings.setValue("character_useall", this->checkCharacterUseall->isChecked());
		settings.setValue("character_sep", this->lineCharacterSep->text());
		settings.setValue("character_value", this->lineCharacterValue->text());
	settings.endGroup();
	if (settings.value("language", "en").toString() != this->codes.at(this->comboLanguages->currentIndex()))
	{
		settings.setValue("language", this->codes.at(this->comboLanguages->currentIndex()));
		parent->loadLanguage(this->codes.at(this->comboLanguages->currentIndex()));
	}
	this->close();
}