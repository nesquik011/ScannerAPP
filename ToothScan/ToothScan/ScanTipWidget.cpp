#include "ScanTipWidget.h"

ScanTipWidget::ScanTipWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->InitVariable();
	//this->upperCompenConstructIHM2();
	//this->lowerSplitScanConstructIHM5();
	//this->upperPlaceConstructIHM1();
}

ScanTipWidget::~ScanTipWidget()
{
}

void ScanTipWidget::InitVariable()
{
	//top
	QFont ft;
	ft.setPointSize(14);
	primaryTipLabel = new QLabel(this);
	primaryTipLabel->setFont(ft);
	secondTipLabel = new QLabel(this);
	ft.setPointSize(11);
	secondTipLabel->setFont(ft);

	//middle
	imageTipLabel = new QLabel(this);
	
	compensationButton = new QPushButton(QStringLiteral("增加扫描"), this);//增加补扫
	discardButton = new QPushButton(QStringLiteral("丢弃增扫"), this);//丢弃补扫
	rotationLabel = new QLabel(QStringLiteral("旋转角度:"), this);
	rotationLineEdit = new QLineEdit(this);//旋转角度
	rotationLineEdit->setFixedSize(50, 20);
	waverLineEdit = new QLineEdit(this);//摆动角度
	waverLabel = new QLabel(QStringLiteral("摆动角度:"), this);
	waverLineEdit->setFixedSize(50, 20);
	cutHeightLabel = new QLabel(QStringLiteral("切割高度:"), this);
	cutHeightLineEdit = new QLineEdit(this);//切割高度
	cutHeightLineEdit->setFixedSize(50, 20);
	spinCutBox = new QSpinBox();//切割控制
	sliderCut = new QSlider(Qt::Horizontal);
	cutHeightButton = new QPushButton(QStringLiteral("切割模型"), this);//切割高度应用
	discardCutHeightButton = new QPushButton(QStringLiteral("丢弃切割"), this);//丢弃切割高度应用
	saveCutHeightButton = new QPushButton(QStringLiteral("保存为默认切割高度"), this);//保存当前切割高度

	upperShowButton = new QPushButton(this);
	lowerShowButton = new QPushButton(this);

	for (int i = 0; i < 8; i++)
	{
		QLabel *toothQLabel = new QLabel();
		toothQLabel->setFixedSize(40, 40);
		toothQLabel->setStyleSheet("border-width: 2px;border-style: solid;border-color: rgb(255, 128, 128);background-color:rgb(255,255,0);");
		toothList.append(toothQLabel);

		toothList[i]->setObjectName(QString::number(i, 10));
	}

	//bottom
	backStepButton = new QPushButton(this);
	forwardStepButton = new QPushButton(this);	
}

void ScanTipWidget::placeConstruct1()
{
	if (this->layout() != NULL)
	{
		delete this->layout();
	}
	QVBoxLayout *totalVLayout = new QVBoxLayout();
	//total
	QWidget *centerWidget = new QWidget();
	QVBoxLayout *centerLayout = new QVBoxLayout(centerWidget);

	//top
	QWidget *topWidget = new QWidget();
	QVBoxLayout *topHLayout = new QVBoxLayout(topWidget);

	topHLayout->addWidget(primaryTipLabel);
	topHLayout->addStretch(1);
	topHLayout->addWidget(secondTipLabel);
	topHLayout->addStretch(2);
	topWidget->setFixedSize(300, 100);

	//middle
	QWidget *middleVWidget = new QWidget();
	QVBoxLayout *middleVLayout = new QVBoxLayout(middleVWidget);
	QWidget *middleWidget = new QWidget();
	QHBoxLayout *middleHLayout = new QHBoxLayout(middleWidget);
	
	middleVLayout->addStretch();
	middleVLayout->addWidget(imageTipLabel);
	middleVLayout->addStretch();
	
	middleHLayout->addStretch();
	middleHLayout->addWidget(middleVWidget);
	middleHLayout->addStretch();

	middleWidget->setFixedSize(300, 500);

	//bottom
	QWidget *bottomWidget = new QWidget();
	QHBoxLayout *bottomHLayout = new QHBoxLayout(bottomWidget);
	bottomHLayout->addStretch(2);
	bottomHLayout->addWidget(backStepButton);
	bottomHLayout->addStretch(9);
	bottomHLayout->addWidget(forwardStepButton);
	bottomHLayout->addStretch(2);
	bottomWidget->setFixedSize(300, 100);

	//total
	centerLayout->addStretch(2);
	centerLayout->addWidget(topWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(middleWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(bottomWidget);
	centerLayout->addStretch(2);
	centerLayout->setMargin(0);
	centerLayout->setSpacing(0);

	totalVLayout->addWidget(centerWidget);
	centerWidget->setObjectName("TipWidget");
	centerWidget->setStyleSheet("QWidget#TipWidget{border-width: 2px;border-style: solid;border-color: rgb(20,20,20)}");
	
	this->setLayout(totalVLayout);
	
}

void ScanTipWidget::compenConstruct2()
{
	if (this->layout() != NULL)
	{
		delete this->layout();
	}
	QVBoxLayout *totalVLayout = new QVBoxLayout();
	//total
	QWidget *centerWidget = new QWidget(this);
	QVBoxLayout *centerLayout = new QVBoxLayout(centerWidget);

	//top
	QWidget *topWidget = new QWidget();
	QVBoxLayout *topHLayout = new QVBoxLayout(topWidget);

	topHLayout->addWidget(primaryTipLabel);
	//topHLayout->addStretch(1);
	topHLayout->addWidget(secondTipLabel);
	//topHLayout->addStretch();
	topWidget->setFixedSize(300, 120);

	//middle
	QWidget *middleGWidget = new QWidget();
	QGridLayout *middleGLayout = new QGridLayout(middleGWidget);

	/*QWidget *middleLeftFWidget = new QWidget(middleGWidget);
	QFormLayout *middleLeftFLayout = new QFormLayout(middleLeftFWidget);
	middleLeftFLayout->addRow(QStringLiteral("旋转角度:"), rotationLineEdit);
	middleLeftFLayout->addRow(QStringLiteral("切割高度:"), cutHeightLineEdit);
	middleLeftFLayout->setVerticalSpacing(0);
	middleLeftFLayout->setHorizontalSpacing(0);
	middleLeftFLayout->setMargin(0);
	middleLeftFWidget->setFixedHeight(40);*/
	
	/*QWidget *middleTopHWidget = new QWidget(middleGWidget);
	QHBoxLayout *middleTopHLayout = new QHBoxLayout(middleTopHWidget);
	middleRightTopHWidget->setFixedSize(105, 20);

	middleTopHLayout->addWidget(rotationLabel);
	middleTopHLayout->addWidget(rotationLineEdit);
	middleTopHLayout->addWidget(waverLabel);
	middleTopHLayout->addWidget(waverLineEdit);
	middleTopHLayout->setMargin(0);
	middleTopHLayout->setSpacing(0);*/

	QWidget *middleRightBottomHWidget = new QWidget();
	QHBoxLayout *middleRightBottomHLayout = new QHBoxLayout(middleRightBottomHWidget);
	middleRightBottomHWidget->setFixedSize(113, 20);
	middleRightBottomHLayout->addWidget(spinCutBox);
	middleRightBottomHLayout->addWidget(sliderCut);
	middleRightBottomHLayout->setMargin(0);
	middleRightBottomHLayout->setSpacing(0);
	
	/*QWidget *middleRightVWidget = new QWidget(middleGWidget);
	QVBoxLayout *middleRightVLayout = new QVBoxLayout(middleRightVWidget);
	middleRightVWidget->setFixedSize(200,40);
	middleRightVLayout->addWidget(middleRightTopHWidget);
	middleRightVLayout->addWidget(middleRightBottomHWidget);
	middleRightVLayout->setMargin(0);
	middleRightVLayout->setSpacing(0);*/

	middleGLayout->addWidget(rotationLabel,0,0,1,1);
	middleGLayout->addWidget(rotationLineEdit, 0, 1, 1, 1);
	middleGLayout->addWidget(waverLabel, 0, 2, 1, 1);
	middleGLayout->addWidget(waverLineEdit, 0, 3, 1, 1);
	middleGLayout->addWidget(cutHeightLabel, 1, 0, 1, 1);
	middleGLayout->addWidget(cutHeightLineEdit, 1, 1, 1, 1);
	middleGLayout->addWidget(middleRightBottomHWidget, 1, 2, 1, 2);

	middleGLayout->addWidget(cutHeightButton, 2, 0, 1, 2);
	middleGLayout->addWidget(discardCutHeightButton, 2, 2, 1, 2);
	middleGLayout->addWidget(saveCutHeightButton, 3, 0, 1, 4);
	middleGLayout->addWidget(compensationButton, 4, 0, 1, 2);
	middleGLayout->addWidget(discardButton, 4, 2, 1, 2);
	middleGWidget->setFixedSize(250,150);

	QWidget *middleWidget = new QWidget();
	QHBoxLayout *middleHLayout = new QHBoxLayout(middleWidget);
	middleHLayout->addStretch(2);
	middleHLayout->addWidget(middleGWidget);
	middleHLayout->addStretch(8);
	middleHLayout->setSpacing(0);
	middleHLayout->setMargin(0);
	middleWidget->setFixedSize(300, 450);

	//bottom
	QWidget *bottomWidget = new QWidget();
	QHBoxLayout *bottomHLayout = new QHBoxLayout(bottomWidget);
	bottomHLayout->addStretch(2);
	bottomHLayout->addWidget(backStepButton);
	bottomHLayout->addStretch(9);
	bottomHLayout->addWidget(forwardStepButton);
	bottomHLayout->addStretch(2);
	bottomWidget->setFixedSize(300, 100);

	//total
	centerLayout->addStretch(2);
	centerLayout->addWidget(topWidget);
	//centerLayout->addStretch(1);
	centerLayout->addWidget(middleWidget);
	centerLayout->addStretch(2);
	centerLayout->addWidget(bottomWidget);
	centerLayout->addStretch(3);
	centerLayout->setMargin(0);
	centerLayout->setSpacing(0);

	totalVLayout->addWidget(centerWidget);
	centerWidget->setObjectName("TipWidget");
	centerWidget->setStyleSheet("QWidget#TipWidget{border-width: 2px;border-style: solid;border-color: rgb(20,20,20)}");
	this->setLayout(totalVLayout);
	
}

void ScanTipWidget::finishConstruct3()
{
	if (this->layout() != NULL)
	{
		delete this->layout();
	}
	QVBoxLayout *totalVLayout = new QVBoxLayout();
	//total
	QWidget *centerWidget = new QWidget(this);
	QVBoxLayout *centerLayout = new QVBoxLayout(centerWidget);

	//top
	QWidget *topWidget = new QWidget();
	QVBoxLayout *topHLayout = new QVBoxLayout(topWidget);

	topHLayout->addWidget(primaryTipLabel);
	topHLayout->addStretch(1);
	topHLayout->addWidget(secondTipLabel);
	topHLayout->addStretch(2);
	topWidget->setFixedSize(300, 100);

	//middle
	QWidget *middleVWidget = new QWidget();
	QVBoxLayout *middleVLayout = new QVBoxLayout(middleVWidget);
	middleVLayout->addStretch();
	middleVLayout->addWidget(upperShowButton);
	middleVLayout->addWidget(lowerShowButton);
	middleVLayout->addStretch();
	QWidget *middleWidget = new QWidget();
	QHBoxLayout *middleHLayout = new QHBoxLayout(middleWidget);
	middleHLayout->addStretch();
	middleHLayout->addWidget(middleVWidget);
	middleHLayout->addStretch();
	middleWidget->setFixedSize(300, 500);

	//bottom
	QWidget *bottomWidget = new QWidget();
	QHBoxLayout *bottomHLayout = new QHBoxLayout(bottomWidget);
	bottomHLayout->addStretch(2);
	bottomHLayout->addWidget(backStepButton);
	bottomHLayout->addStretch(9);
	bottomHLayout->addWidget(forwardStepButton);
	bottomHLayout->addStretch(2);
	bottomWidget->setFixedSize(300, 100);

	//total
	centerLayout->addStretch(2);
	centerLayout->addWidget(topWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(middleWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(bottomWidget);
	centerLayout->addStretch(2);
	centerLayout->setMargin(0);
	centerLayout->setSpacing(0);

	totalVLayout->addWidget(centerWidget);
	centerWidget->setObjectName("TipWidget");
	centerWidget->setStyleSheet("QWidget#TipWidget{border-width: 2px;border-style: solid;border-color: rgb(20,20,20)}");
	this->setLayout(totalVLayout);
	
}

void ScanTipWidget::splitScanConstruct1()
{
	if (this->layout() != NULL)
	{
		delete this->layout();
	}
	QVBoxLayout *totalVLayout = new QVBoxLayout(this);

	//total
	QWidget *centerWidget = new QWidget(this);
	QVBoxLayout *centerLayout = new QVBoxLayout(centerWidget);

	//top
	QWidget *topWidget = new QWidget();
	QVBoxLayout *topHLayout = new QVBoxLayout(topWidget);

	topHLayout->addWidget(primaryTipLabel);
	topHLayout->addStretch(1);
	topHLayout->addWidget(secondTipLabel);
	topHLayout->addStretch(2);
	topWidget->setFixedSize(300, 100);

	//middle
	QWidget *middleWidget = new QWidget();
	middleWidget->setFixedSize(300, 500);
	for (int i = 0; i < 8; i++)
	{
		toothList[i]->setParent(middleWidget);
	}
	toothList[0]->setGeometry(125, 105, 20, 20);
	toothList[1]->setGeometry(125, 20, 20, 20);
	toothList[2]->setGeometry(180, 60, 20, 20);
	toothList[3]->setGeometry(205, 120, 20, 20);
	toothList[4]->setGeometry(160, 170, 20, 20);
	toothList[5]->setGeometry(90, 170, 20, 20);
	toothList[6]->setGeometry(45, 120, 20, 20);
	toothList[7]->setGeometry(70, 60, 20, 20);

	//bottom
	QWidget *bottomWidget = new QWidget();
	QHBoxLayout *bottomHLayout = new QHBoxLayout(bottomWidget);
	bottomHLayout->addStretch(2);
	bottomHLayout->addWidget(backStepButton);
	bottomHLayout->addStretch(9);
	bottomHLayout->addWidget(forwardStepButton);
	bottomHLayout->addStretch(2);
	bottomWidget->setFixedSize(300, 100);

	//total
	centerLayout->addStretch(2);
	centerLayout->addWidget(topWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(middleWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(bottomWidget);
	centerLayout->addStretch(2);
	centerLayout->setMargin(0);
	centerLayout->setSpacing(0);

	totalVLayout->addWidget(centerWidget);

	centerWidget->setObjectName("TipWidget");
	centerWidget->setStyleSheet("QWidget#TipWidget{border-width: 2px;border-style: solid;border-color: rgb(20,20,20)}");
	this->setLayout(totalVLayout);
}

void ScanTipWidget::placeVariable1()
{
	primaryTipLabel->setVisible(true);
	secondTipLabel->setVisible(true);

	imageTipLabel->setVisible(true);

	rotationLabel->setVisible(false);
	cutHeightLabel->setVisible(false);

	compensationButton->setVisible(false);//增加补扫
	discardButton->setVisible(false);//丢弃补扫
	rotationLineEdit->setVisible(false);//旋转角度
	rotationLineEdit->setVisible(false);
	waverLineEdit->setVisible(false);//摆动角度
	waverLabel->setVisible(false);
	cutHeightLineEdit->setVisible(false);//切割高度
	spinCutBox->setVisible(false);//切割控制
	sliderCut->setVisible(false);
	cutHeightButton->setVisible(false);//切割高度应用
	discardCutHeightButton->setVisible(false);//丢弃切割高度应用
	saveCutHeightButton->setVisible(false);//保存当前切割高度

	upperShowButton->setVisible(false);
	lowerShowButton->setVisible(false);

	for (int i = 0; i < 8; i++)
	{
		toothList[i]->setVisible(false);
	}

	backStepButton->setVisible(true);
	forwardStepButton->setVisible(true);
}

void ScanTipWidget::compenVariable2()
{
	primaryTipLabel->setVisible(true);
	secondTipLabel->setVisible(true);

	imageTipLabel->setVisible(false);

	rotationLabel->setVisible(true);
	cutHeightLabel->setVisible(true);
	compensationButton->setVisible(true);//增加补扫
	discardButton->setVisible(true);//丢弃补扫
	rotationLineEdit->setVisible(true);//旋转角度
	rotationLineEdit->setVisible(true);
	waverLineEdit->setVisible(true);//摆动角度
	waverLabel->setVisible(true);
	cutHeightLineEdit->setVisible(true);//切割高度
	spinCutBox->setVisible(true);//切割控制
	sliderCut->setVisible(true);
	cutHeightButton->setVisible(true);//切割高度应用
	discardCutHeightButton->setVisible(true);//丢弃切割高度应用
	saveCutHeightButton->setVisible(true);//保存当前切割高度

	upperShowButton->setVisible(false);
	lowerShowButton->setVisible(false);

	for (int i = 0; i < 8; i++)
	{
		toothList[i]->setVisible(false);
	}
	backStepButton->setVisible(true);
	forwardStepButton->setVisible(true);
}

void ScanTipWidget::finishVariable3()
{
	primaryTipLabel->setVisible(true);
	secondTipLabel->setVisible(true);

	imageTipLabel->setVisible(false);

	rotationLabel->setVisible(false);
	cutHeightLabel->setVisible(false);
	compensationButton->setVisible(false);//增加补扫
	discardButton->setVisible(false);//丢弃补扫
	rotationLineEdit->setVisible(false);//旋转角度
	rotationLineEdit->setVisible(false);
	waverLineEdit->setVisible(false);//摆动角度
	waverLabel->setVisible(false);
	cutHeightLineEdit->setVisible(false);//切割高度
	spinCutBox->setVisible(false);//切割控制
	sliderCut->setVisible(false);
	cutHeightButton->setVisible(false);//切割高度应用
	discardCutHeightButton->setVisible(false);//丢弃切割高度应用
	saveCutHeightButton->setVisible(false);//保存当前切割高度

	upperShowButton->setVisible(true);
	lowerShowButton->setVisible(true);

	for (int i = 0; i < 8; i++)
	{
		toothList[i]->setVisible(false);
	}
	backStepButton->setVisible(true);
	forwardStepButton->setVisible(true);
}

void ScanTipWidget::splitScanVariable4()
{
	primaryTipLabel->setVisible(true);
	secondTipLabel->setVisible(true);

	imageTipLabel->setVisible(false);

	rotationLabel->setVisible(false);
	cutHeightLabel->setVisible(false);
	compensationButton->setVisible(false);//增加补扫
	discardButton->setVisible(false);//丢弃补扫
	rotationLineEdit->setVisible(false);//旋转角度
	rotationLineEdit->setVisible(false);
	waverLineEdit->setVisible(false);//摆动角度
	waverLabel->setVisible(false);
	cutHeightLineEdit->setVisible(false);//切割高度
	spinCutBox->setVisible(false);//切割控制
	sliderCut->setVisible(false);
	cutHeightButton->setVisible(false);//切割高度应用
	discardCutHeightButton->setVisible(false);//丢弃切割高度应用
	saveCutHeightButton->setVisible(false);//保存当前切割高度

	upperShowButton->setVisible(false);
	lowerShowButton->setVisible(false);

	for (int i = 0; i < 8; i++)
	{
		toothList[i]->setVisible(true);
	}
	backStepButton->setVisible(true);
	forwardStepButton->setVisible(true);
}

void ScanTipWidget::allPlaceConstructIHM1()
{
	//全颌—————1—————
	placeVariable1();
	primaryTipLabel->setText(QStringLiteral("请插入全颌模型"));
	secondTipLabel->setVisible(false);
	imageTipLabel->setFixedSize(180, 120);
	imageTipLabel->setPixmap(QPixmap(":/MainWidget/Resources/images/alljaw.png"));
	backStepButton->setVisible(false);
	forwardStepButton->setText(QStringLiteral("扫  描"));

	placeConstruct1();
}

void ScanTipWidget::allCompenConstructIHM2()
{
	//全颌—————2—————
	compenVariable2();
	primaryTipLabel->setText(QStringLiteral("全颌模型"));
	secondTipLabel->setText(QStringLiteral("旋转模型到你想要增加扫描的位置，通过“增加补扫”可添加新扫描数据"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("后  退"));
	forwardStepButton->setText(QStringLiteral("下一步"));

	compenConstruct2();
}

void ScanTipWidget::allPlaceConstructIHM3()
{
	//全颌—————3—————
	placeVariable1();
	primaryTipLabel->setText(QStringLiteral("请移除全郃模型，插入下颌模型"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setVisible(false);
	imageTipLabel->setFixedSize(200, 130);
	imageTipLabel->setPixmap(QPixmap(":/MainWidget/Resources/images/lowerjaw.png"));
	backStepButton->setText(QStringLiteral("后  退"));
	forwardStepButton->setText(QStringLiteral("扫  描"));
	
	placeConstruct1();
}

void ScanTipWidget::allCompenConstructIHM4()
{
	//全颌—————4—————
	compenVariable2();
	primaryTipLabel->setText(QStringLiteral("下颌模型"));
	secondTipLabel->setText(QStringLiteral("旋转模型到你想要增加扫描的位置，通过“增加补扫”可添加新扫描数据"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("后  退"));
	forwardStepButton->setText(QStringLiteral("下一步"));
	
	compenConstruct2();
}

void ScanTipWidget::allPlaceConstructIHM5()
{
	//全颌—————5—————
	placeVariable1();
	primaryTipLabel->setText(QStringLiteral("请移除下颌模型，插入上颌模型"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setVisible(false);
	imageTipLabel->setFixedSize(200, 130);
	imageTipLabel->setPixmap(QPixmap(":/MainWidget/Resources/images/upperjaw.png"));
	backStepButton->setText(QStringLiteral("后  退"));
	forwardStepButton->setText(QStringLiteral("扫  描"));
	
	placeConstruct1();
}

void ScanTipWidget::allCompenConstructIHM6()
{
	//全颌—————6—————
	compenVariable2();
	primaryTipLabel->setText(QStringLiteral("上颌模型"));
	secondTipLabel->setText(QStringLiteral("旋转模型到你想要增加扫描的位置，通过“增加补扫”可添加新扫描数据"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("后  退"));
	forwardStepButton->setText(QStringLiteral("下一步"));
	
	compenConstruct2();
}

void ScanTipWidget::allFinishConstructIHM7()
{
	//全颌—————7—————
	finishVariable3();
	primaryTipLabel->setText(QStringLiteral("拼接完成"));
	secondTipLabel->setText(QStringLiteral("可以修剪模型数据"));
	upperShowButton->setFixedSize(200, 100);
	upperShowButton->setStyleSheet("QPushButton{border-image: url(:/MainWidget/Resources/images/upperjaw_no.png);}"
		"QPushButton:hover{border-image: url(:/MainWidget/Resources/images/upperjaw_yes.png);}");
	lowerShowButton->setFixedSize(200,100);
	lowerShowButton->setStyleSheet("QPushButton{border-image: url(:/MainWidget/Resources/images/lowerjaw_no.png);}"
		"QPushButton:hover{border-image: url(:/MainWidget/Resources/images/lowerjaw_yes.png);}");
	backStepButton->setText(QStringLiteral("后  退"));
	forwardStepButton->setText(QStringLiteral("完  成"));

	finishConstruct3();
}

void ScanTipWidget::upperPlaceConstructIHM1()
{
	//上颌—————1—————
	placeVariable1();
	primaryTipLabel->setText(QStringLiteral("请插入上颌模型"));
	secondTipLabel->setVisible(false);
	imageTipLabel->setFixedSize(200, 130);
	imageTipLabel->setPixmap(QPixmap(":/MainWidget/Resources/images/upperjaw.png"));
	backStepButton->setVisible(false);
	forwardStepButton->setText(QStringLiteral("扫  描"));

	placeConstruct1();
}

void ScanTipWidget::upperCompenConstructIHM2()
{
	//上颌—————2—————
	compenVariable2();
	compenConstruct2();
	primaryTipLabel->setText(QStringLiteral("上颌模型扫描完成，可以修剪模型数据"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setText(QStringLiteral("旋转模型到你想要增加扫描的位置，通过“增加补扫”可添加新扫描数据；或者进行修剪模型数据"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("后  退"));
	forwardStepButton->setText(QStringLiteral("完  成"));
}

void ScanTipWidget::lowerPlaceConstructIHM1()
{
	//下颌—————1—————
	placeVariable1();
	primaryTipLabel->setText(QStringLiteral("请插入下颌模型"));
	secondTipLabel->setVisible(false);
	imageTipLabel->setFixedSize(200, 130);
	imageTipLabel->setPixmap(QPixmap(":/MainWidget/Resources/images/lowerjaw.png"));
	backStepButton->setVisible(false);
	forwardStepButton->setText(QStringLiteral("扫  描"));

	placeConstruct1();
}

void ScanTipWidget::lowerCompenConstructIHM2()
{
	//下颌—————2—————
	compenVariable2();
	compenConstruct2();
	primaryTipLabel->setText(QStringLiteral("下颌模型扫描完成，可以修剪模型数据"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setText(QStringLiteral("旋转模型到你想要增加扫描的位置，通过“增加补扫”可添加新扫描数据；"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("后  退"));
	forwardStepButton->setText(QStringLiteral("完  成"));
}



void ScanTipWidget::upperSplitScanConstructIHM5()
{
	splitScanVariable4();

	primaryTipLabel->setText(QStringLiteral("请移除上颌模型，插入代型盘"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setVisible(false);
	backStepButton->setText(QStringLiteral("后  退"));
	forwardStepButton->setText(QStringLiteral("下一步"));

	splitScanConstruct1();
}

void ScanTipWidget::upperSplitRemoveConstructIHM6()
{
	compenVariable2();
	primaryTipLabel->setText(QStringLiteral("代型模型"));
	secondTipLabel->setText(QStringLiteral("旋转模型到你想要增加扫描的位置，通过“增加补扫”可添加新扫描数据"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("后  退"));
	forwardStepButton->setText(QStringLiteral("下一步"));

	compenConstruct2();
}

void ScanTipWidget::upperSplitFinishConstructIHM7()
{
	//全颌—————7—————
	finishVariable3();
	primaryTipLabel->setText(QStringLiteral("上颌拼接完成"));
	secondTipLabel->setText(QStringLiteral("可以修剪模型数据"));
	upperShowButton->setFixedSize(200, 100);
	upperShowButton->setStyleSheet("QPushButton{border-image: url(:/MainWidget/Resources/images/upperjaw_no.png);}"
		"QPushButton:hover{border-image: url(:/MainWidget/Resources/images/upperjaw_yes.png);}");
	lowerShowButton->setVisible(false);
	backStepButton->setText(QStringLiteral("后  退"));
	forwardStepButton->setText(QStringLiteral("完  成"));

	finishConstruct3();
}

void ScanTipWidget::lowerSplitScanConstructIHM5()
{
	splitScanVariable4();
	splitScanConstruct1();
	primaryTipLabel->setText(QStringLiteral("请移除下颌模型，插入代型盘"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setVisible(false);
	backStepButton->setText(QStringLiteral("后  退"));
	forwardStepButton->setText(QStringLiteral("下一步"));

	
}

void ScanTipWidget::lowerSplitRemoveConstructIHM6()
{
	compenVariable2();
	primaryTipLabel->setText(QStringLiteral("代型模型"));
	secondTipLabel->setText(QStringLiteral("旋转模型到你想要增加扫描的位置，通过“增加补扫”可添加新扫描数据"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("后  退"));
	forwardStepButton->setText(QStringLiteral("下一步"));

	compenConstruct2();
}

void ScanTipWidget::lowerSplitFinishConstructIHM7()
{
	finishVariable3();
	primaryTipLabel->setText(QStringLiteral("下颌拼接完成"));
	secondTipLabel->setText(QStringLiteral("可以修剪模型数据"));
	lowerShowButton->setFixedSize(200, 100);
	lowerShowButton->setStyleSheet("QPushButton{border-image: url(:/MainWidget/Resources/images/lowerjaw_no.png);}"
		"QPushButton:hover{border-image: url(:/MainWidget/Resources/images/lowerjaw_yes.png);}");
	upperShowButton->setVisible(false);
	backStepButton->setText(QStringLiteral("后  退"));
	forwardStepButton->setText(QStringLiteral("完  成"));

	finishConstruct3();
}

void ScanTipWidget::allSplitFinishConstructIHM8()
{
	finishVariable3();
	primaryTipLabel->setText(QStringLiteral("拼接完成"));
	secondTipLabel->setText(QStringLiteral("可以修剪模型数据"));
	upperShowButton->setFixedSize(200, 100);
	upperShowButton->setStyleSheet("QPushButton{border-image: url(:/MainWidget/Resources/images/upperjaw_no.png);}"
		"QPushButton:hover{border-image: url(:/MainWidget/Resources/images/upperjaw_yes.png);}");
	lowerShowButton->setFixedSize(200, 100);
	lowerShowButton->setStyleSheet("QPushButton{border-image: url(:/MainWidget/Resources/images/lowerjaw_no.png);}"
		"QPushButton:hover{border-image: url(:/MainWidget/Resources/images/lowerjaw_yes.png);}");
	backStepButton->setText(QStringLiteral("后  退"));
	forwardStepButton->setText(QStringLiteral("完  成"));

	finishConstruct3();
}