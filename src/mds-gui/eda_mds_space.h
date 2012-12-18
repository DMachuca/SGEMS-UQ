#ifndef EDA_MDS_SPACE_H
#define EDA_MDS_SPACE_H

#include <QObject>
#include <GsTLAppli/gui/charts/eda_charts.h>
#include <GsTLAppli/gui/charts/chart_mdi_area.h>
#include <common.h>
#include <QFrame>
#include <GsTLAppli/appli/project.h>
#include <QListView>
#include <QStringListModel>

#include <metric_manager_repository.h>
#include <MdsSpaceObjectModel.h>

// GsTL Dependencies
#include <GsTL/utils/smartptr.h>

// GsTLAppli Dependencies
#include <GsTLAppli/utils/manager.h>
#include <GsTLAppli/appli/manager_repository.h>
#include <GsTLAppli/appli/root_model.h>
#include <GsTLAppli/appli/project.h>
#include <GsTLAppli/extra/qtplugins/project_proxy_model.h>
#include <GsTLAppli/extra/qtplugins/property_proxy_model.h>


#include <mdsspacecreatordialog.h>

//#include <actions/UncertainSpaceIOAction.h>
//#include <filters/MDSUncertaintySpaceInputFilter.h>
//#include <filters/MDSUncertaintySpaceOutputFilter.h>

#include <QVBoxLayout>
#include <QGroupBox>
#include <QSplitter>
#include <QPushButton>
#include <QFileDialog>
#include <QTreeView>


class METRICSGUI_DECL EDA_mds_space : public EDA_chart
{
    Q_OBJECT

public:
    explicit EDA_mds_space(Chart_mdi_area* mdi_area, QWidget *parent = 0);
    ~EDA_mds_space();

public slots:
    void updateModel(){}
    void createNewMDSSpace();
    void deleteMDSSpace();
    void updatePropertyExplorer(QModelIndex mdsSpaceIndex);
    void updateResponseExplorer(QModelIndex mdsSpaceIndex);


private slots:
    void display_mds_space();

protected:
    GsTL_project *proj_;
    QListView *mdsObjectView_;
    QModelIndex mdsBaseIndex;
    
    QTreeView* responseListTreeView_;
    QTreeView* propertyListTreeView_;
    QTreeView* mdsListTreeView_;

    Filter_root_proxy_model* proxy_model;
    QStandardItemModel  *emptyModel;

    void setMDSTreeView();
    void setTestTreeView();

};



class METRICSGUI_DECL EDA_mds_space_factory : public EDA_chart_factory 
{

public:

  static Named_interface* create_new_interface(std::string&) {
    return new EDA_mds_space_factory;
  }

  EDA_mds_space_factory(){}
  ~EDA_mds_space_factory(){}

  virtual QString title_name() const {return "MDS Space";}
  virtual QString tab_name() const{return "Responses";}
  std::string name() const {return "MDS Space";}

  virtual EDA_chart* get_interface(Chart_mdi_area* mdi_area){return new EDA_mds_space(mdi_area);}

};

#endif // EDA_MDS_SPACE_H
