DOC_PROJ_NAME=LamKit

# Info.
echo "Starting appledoc generation into $LAM_DOCGEN_BASE_PATH…"

appledoc \
--logformat xcode \
--project-name $DOC_PROJ_NAME \
--project-company "L'Atelier du mobile" \
--company-id com.atelierdumobile \
--output "$LAM_DOCGEN_BASE_PATH/iOS/$DOC_PROJ_NAME" \
--keep-undocumented-objects \
--keep-undocumented-members \
--keep-intermediate-files \
--ignore .m \
--index-desc ./Docgen/index.markdown \
Classes

# Add the Dash index.
cp "$LAM_DOCGEN_BASE_PATH/iOS/$DOC_PROJ_NAME/docset/"\
"Contents/Resources/Documents/index.html" \
"$LAM_DOCGEN_BASE_PATH/iOS/$DOC_PROJ_NAME/docset/"\
"Contents/Resources/Documents/dash-browse-index.html"

# Add the Dash icon.
cp "Docgen/icon.png" \
"$LAM_DOCGEN_BASE_PATH/iOS/$DOC_PROJ_NAME/docset/icon.png"

rm -rf "$LAM_DOCGEN_BASE_PATH/iOS/$DOC_PROJ_NAME/$DOC_PROJ_NAME.docset"

mv "$LAM_DOCGEN_BASE_PATH/iOS/$DOC_PROJ_NAME/docset" \
"$LAM_DOCGEN_BASE_PATH/iOS/$DOC_PROJ_NAME/$DOC_PROJ_NAME.docset"
