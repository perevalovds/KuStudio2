#pragma once

//Список зарегистрированных модулей

#include "kuMain.h"
#include<QStringList>
#include<Module.h>

struct ModuleInfo {
    QString type_name;      //имя типа модуля
    QString description;    //описание
    QString proposed_name;    //рекомендуемое имя для создаваемого объекта
    ModuleInfo(QString type0, QString descr0, QString proposed_name0) {
        type_name = type0;
        description = descr0;
        proposed_name = proposed_name0;
    }
};


struct Modules {
    Modules();
    QStringList modules_names();    //Имена доступных модулей
    QStringList modules_descriptions();    //Описания доступных модулей
    QStringList modules_proposed_names();    //Предлагаемые названия для объектов модулей

    Module *createModule( QString name, QString type );

protected:
    vector<ModuleInfo> reg_modules_;
    void reg_module(QString type0, QString descr0, QString proposed_name0);
};

extern Modules modules;
