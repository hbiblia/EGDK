#ifndef __ERMINE_EOBJECT_H__
#define __ERMINE_EOBJECT_H__
#include <stdio.h>
#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

// -----------------------
// --- DEFINE ABS
// -----------------------

typedef struct _ErmineObject ErmineObject;
typedef struct _ErmineObjectClass ErmineObjectClass;
typedef struct _ErmineObjectPrivate ErmineObjectPrivate;

#define ERMINE_TYPE_OBJECT ermine_object_get_type()
G_DECLARE_DERIVABLE_TYPE(ErmineObject, ermine_object, ERMINE, OBJECT, GObject)

struct _ErmineObjectPrivate
{
    GObject parent_instance;
};
struct _ErmineObjectClass
{
    GObjectClass parent_class;
};

// -----------------------
// --- METHODS
// -----------------------
ErmineObject *ermine_object_new(void);

G_END_DECLS

#endif